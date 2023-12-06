import json

with open('orders.json', 'r+') as f:
    orders = json.load(f)
    for order in orders:
        if order["id"] == 8 and order["otp"] == 691:
            print("alsoYES")