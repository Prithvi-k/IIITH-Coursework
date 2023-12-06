from flask import Flask, render_template, request, redirect, url_for
import json
from flask_cors import CORS

app = Flask(__name__, static_folder='static/')
CORS(app)

# Initial route to display the registration form


@app.route('/')
def index():
    # Initially, the user will be redirected to the registration form
    return render_template('form.html')

# Route after form is submitted


@app.route('/register', methods=['POST'])
def register():
    # On submitting, Get the user details from the form
    name = request.form['name']
    email = request.form['email']
    password = request.form['password']

    # Store the user details in a file
    user_data = {'name': name, 'email': email, 'password': password}
    with open('users.txt', 'a') as f:
        f.write(json.dumps(user_data) + '\n')

    # Display the registration details of the user
    return render_template('details.html', name=name, email=email, password=password)


# Route to display the details of specific user


@app.route('/users/<email>', methods=['GET'])
def user_details(email):
    # Display the details of the user with the given email
    with open('users.txt', 'r') as f:
        for line in f:
            user_data = json.loads(line)
            if user_data['email'] == email:
                return render_template('individual.html', user_data=user_data)
    # If the user with the given email is not found, display a message
    return render_template('individual.html', user_data=None)


# Route to display the details of all users


@app.route('/users', methods=['GET'])
def all_users():
    users = []
    with open('users.txt', 'r') as f:
        for line in f:
            user_data = json.loads(line)
            users.append(user_data)
    return render_template('all_users.html', users=users)


# Route to delete the details of all users


@app.route('/delete', methods=['POST'])
def delete():
    try:
        # Delete the contents of the file
        with open('users.txt', 'w') as f:
            f.write('')
        # Redirect the user back to the users page
        return redirect('/users')
    except Exception as e:
        # Return an error message with a 500 status code
        return f"An error occurred: {e}", 500


if __name__ == '__main__':
    app.run(debug=True)
