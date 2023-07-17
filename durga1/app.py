from flask import Flask, render_template, request, redirect, url_for

app = Flask(__name__)

def validate_password(password):
    data = []
    k = 0

    if len(password) < 8:
        data.append("1. Password must contain 8 characters")
        k += 1

    if not any(char.islower() for char in password) or not any(char.isupper() for char in password):
        data.append("2. Password must contain both upper and lower case letters")
        k += 1

    if not password[-1].isdigit():
        data.append("3. Password must end with a number")
        k += 1

    if k == 0:
        data.append("Success")

    return data

@app.route('/', methods=['GET', 'POST'])
def validate_form():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        validate_data = validate_password(password)

        if validate_data[0] == "Success":
            return redirect(url_for('success'))
        else:
            return redirect(url_for('invalid'))

    return render_template('index.html')

@app.route('/success')
def success():
    return render_template('success.html')

@app.route('/invalid')
def invalid():
    return render_template('invalid.html')

if __name__ == '__main__':
    app.run(debug=True)
