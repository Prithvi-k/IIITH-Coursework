fetch("/datashow")
    .then(response => response.json())
    .then(jsonData => {
        var num = jsonData.length;
        console.log(num);

        for (var i = 0; i < num; i++) {
            var data = jsonData[i];
            // console.log(data);

            if (data.order_status == "searching for delivery partner") {

                var order_number = data.order_number;
                var name = data.name;
                var number = data.phone;
                var canteen = data.canteen;
                var hostel = data.hostel;
                var room_number = data.room;
                var price = data.price;
                var order = data.order;
                var quantities = data.quantities;
                // var order_items = '';

                // console.log(order_number)
                // console.log(items)

                // for (let i = 0; i < item_codes.length; i++) {
                //     const code = item_codes[i]
                //     const quantity = quantities[code]
                //     const food_item = items[i]
                //     order_items += `${quantity}x ${food_item}<br>`
                // }
                // console.log(order_items)

                var template =
                    `<div class="order">
                    <div>
                        <h4>User details</h4>
                        <div class="user">
                            <p>Name: ${name}</p>
                            <p>Number: ${number}</p>
                        </div>
    
                        <h4>Order Details</h4>
                        <div class="order-details">
                            <p>Order items: ${order}</p>
                            <p>Canteen: ${canteen}</p>
                        </div>
    
                        <h4>Delivery Details</h4>
                        <div class="delivery-details">
                            <p>Hostel: ${hostel}</p>
                            <p>Room Number: ${room_number}</p>
                        </div>
                    </div>
                    <div class="buttons">
                        <button type="submit" class="btn" onclick="statusChange('${order_number}')">confirm</button>
                    </div>
                </div>
                <br>`

                document.getElementsByClassName("orders")[0].innerHTML += template;
            }

        }

    })