from flask import Flask, render_template, request, jsonify, redirect, url_for
import json
from flask_cors import CORS
import os
import uuid

app = Flask(__name__, static_url_path='/static')
CORS(app)

@app.route('/')
def index():
    return render_template('landing.html')

@app.route('/order')
def home():
    return render_template('order.html')

@app.route('/deliver')
def deliver():
    return render_template('deliver.html')

@app.route('/order_lookup', methods=['GET', 'POST'])
def order_lookup():
    if request.method == 'POST':
        phone_number = request.form.get('phone_number')

        with open('orders.json', 'r') as f:
            data = json.load(f)
        
        orders = []
        for order in data:
            if order['phone'] == phone_number:
                orders.append(order)

        return render_template('status.html', orders=orders)
    return render_template('lookup.html')

@app.route('/datashow',methods=["GET"])
def get_data():
    with open('orders.json', 'r') as f:
        data = json.load(f)
    print(data)
    return jsonify(data)

@app.route('/confirm', methods=['POST'])
def confirm():
    data = request.get_json()
    user_id = int(data.get('id'))
    otp_sent = int(data.get('otp'))
    # print('user_id:', user_id)
    # print('otp_sent:', otp_sent)
    # print(user_id == 8)
    
    with open('orders.json', 'r+') as f:
        orders = json.load(f)
        # print('orders:', orders)
        for order in orders:
            # print(order['id'] == 8)
            if (order['id'] == user_id) and (order['otp'] == otp_sent):
                    orders.remove(order)
                    f.seek(0)
                    json.dump(orders, f)
                    f.truncate()
                    response = {'status': 'success'}
                    # print('response:', response)
                    return jsonify(response)

    response = {'status': 'failure'}
    return jsonify(response)

@app.route('/accept_delivery', methods=['POST'])
def accept_delivery():
    data = request.get_json()
    order_number = data.get('order_number')
    print(order_number)
    delivery_partner_name = data.get('delivery_partner_name')
    delivery_partner_number = int(data.get('delivery_partner_phone'))
    # print(delivery_partner_number)
    # print(type(delivery_partner_number))

    with open('orders.json', 'r+') as f:
         orders = json.load(f)
         for order in orders:
            if order['order_number'] == order_number:
                order['order_status'] = f'On the way ({delivery_partner_name} - {delivery_partner_number})' 
                f.seek(0)
                json.dump(orders, f, indent=4)
                f.truncate()
                response = {'status': 'success'}
                return jsonify(response)
    
    response = {'status': 'failure'}
    return jsonify(response)


@app.route('/place_order', methods=['POST'])
def process_order():
    order_number = str(uuid.uuid4())
    name = request.form.get('name')
    hostel = request.form.get('hostel')
    room = request.form.get('room')
    phone = request.form.get('Phone')
    items = request.form.getlist('items')
    total_price = request.form.get('total_price')
    canteen = request.form.get('canteen')
    tip = request.form.get('tip')
    i = 0
    map = {1005: 'pizza', 2003: 'burger', 3002: 'fries'}
    item_names=[]
    item_str = ''
    quantities = {
            '1005': request.form.get('quantity_1005'),
            '2003': request.form.get('quantity_2003'),
            '3002': request.form.get('quantity_3002')
        }
    for item in items:
        item_names.append(map[int(item)])   
        item_str += map[int(item)]
        item_str += ' x'
        item_str += quantities[item]
        item_str += ' '

    order = {
        'order_number': order_number,
        'name': name,
        'hostel': hostel,
        'room': room,
        'items_sno.': items,
        'item_names': item_names,
        'phone': phone,
        'price': total_price,
        'quantities': quantities,
        'order_status': 'searching for delivery partner',
        'order': item_str,
        'canteen': canteen,
        'tip': tip
    }

    # check if orders file exists
    if os.path.isfile('orders.json'):
        # load existing orders from JSON file
        with open('orders.json', 'r') as f:
            orders = json.load(f)
    else:
        # create empty orders file
        orders = []
        with open('orders.json', 'w') as f:
            json.dump(orders, f)

    # append new order to list
    orders.append(order)

    # write updated list to JSON file
    with open('orders.json', 'w') as f:
        json.dump(orders, f, indent=4)

    return redirect(url_for('order_lookup', phone=phone))

@app.route('/received_delivery', methods=['POST'])
def received_delivery():
    data = request.get_json()
    order_number = data.get('order_number')
    print(order_number)
    response = data.get('response')
    # print(delivery_partner_number)

    with open('orders.json', 'r+') as f:
         f.seek(0)
         orders = json.load(f)
         for order in orders:
            if response.lower() == 'y' or response.lower() == 'yes': 
                if order['order_number'] == order_number and 'On the way' in order['order_status']:
                    order['order_status'] = "Delivered" 
                    f.seek(0)
                    json.dump(orders, f, indent=4)
                    f.truncate()
                    response = {'status': 'success'}
                    return jsonify(response)
    
    response = {'status': 'failure'}
    return jsonify(response)

if __name__ == '__main__':
        app.run(debug=True)