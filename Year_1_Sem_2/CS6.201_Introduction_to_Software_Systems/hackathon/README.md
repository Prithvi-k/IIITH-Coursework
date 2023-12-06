# ISS Hackathon: Team 29
<br/>

## Introducing IIITEats

Ever asked your friend at Tantra to get you some fried rice just because you were too lazy to walk out and get it yourself? But what if your nightmares come true and it turns out none of your friends are at the canteen? Fear no more! Introducing IIITEats: a decentralized freelancing-style delivery solution for the IIIT community to simplify intra-campus deliveries while making some money off of it. Craving a shawarma from Tantra? Just place your order on the app and someone currently at the canteen can deliver it to your room for some extra fee. At some canteen and looking to make a quick buck? Open up the app to see the current orders people have placed so you can deliver it to them!

## Features Implemented
<ul>
    <li>Placing an order: Here a user can input details (user details, order details and address details) and make their order. The user is directed to the 'lookup' page</li>
    <li>Lookup order status: Here, a user can enter their mobile number to retrieve order status</li>
    <li>Delivery Page: Any member near any canteen can open this page to see latest orders made by people</li>
    <li>Order Page: This page shows details of a person's order including delivery status</li>
</ul>

### Packages used

<ul>
    <li>Flask: The main package used to run the backend of the site (storing and processing orders)</li>
    <li>JSON: Package used to read and write to <code>.json</code> files</li>
    <li>Flask_CORS: Package to help manage cross-origin-resource-sharing (CORS) requests</li>
    <li>OS: Used the module to check if <code>.json</code> file exists</li>
    <li>UUID: Used to generate a unique, random order_id for each user</li>
</ul>

### Setup Instructions

<ol>
    <li>Unzip/Extract the files from the compressed <code>29.zip</code> file.</li>
    <li>Navigate to the directory containing the project <code>../29/</code></li>
    <li>Install required packages using <code>pip3 install -r requirements.txt</code></li>
    <li>Start the flask webserver by running <code>python3 app.py</code> in the terminal</li>
    <li>Open the mentioned link in your browser (<code>http://localhost:5000</code> by default)</li>
    <li>This opens up the landing page of our website</li>
</ol>

## Project Done by

<ul>
    <li>Keshava Kishora Nanda</li>
    <li>Siddharth Singh</li>
    <li>Prithvi Karthik</li>
</ul>

### Contributions
<ul>
    <li>Keshava: Delivery Page and CSS</li>
    <li>Siddharth: Order, Lookup and Status Pages</li>
    <li>Prithvi: Flask Backend and CSS</li>
</ul>