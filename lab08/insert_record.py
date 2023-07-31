#!/usr/bin/env python3

import cgi
import cgitb
import mysql.connector

# Enable debugging to view errors on the web page
cgitb.enable()

print("Content-type: text/html\n")

form = cgi.FieldStorage()

if form.getvalue("name") and form.getvalue("midterm1") and form.getvalue("midterm2") and form.getvalue("final"):
    name = form.getvalue("name")
    midterm1 = float(form.getvalue("midterm1"))
    midterm2 = float(form.getvalue("midterm2"))
    final = float(form.getvalue("final"))

    # Calculate the average score
    average_score = (midterm1 + midterm2 + 2 * final) / 4

    # Connect to the database
    db_host = "localhost"
    db_user = "admin"
    db_password = "admin"
    db_name = "student_grades"

    conn = mysql.connector.connect(host=db_host, user=db_user, password=db_password, database=db_name)
    cursor = conn.cursor()

    # Insert the data into the table
    sql = "INSERT INTO student_records (student_name, midterm_exam1, midterm_exam2, final_exam) VALUES (%s, %s, %s, %s)"
    values = (name, midterm1, midterm2, final)
    cursor.execute(sql, values)
    conn.commit()

    cursor.close()
    conn.close()

print("<html>")
print("<head><title>Student Database Interface</title></head>")
print("<body>")
print("<h1>Student Database Interface</h1>")
print("<form action='insert.py' method='post'>")
print("    <label for='name'>Student Name:</label>")
print("    <input type='text' id='name' name='name' required><br>")
print("    <label for='midterm1'>Midterm Exam 1:</label>")
print("    <input type='number' id='midterm1' name='midterm1' step='0.01' required><br>")
print("    <label for='midterm2'>Midterm Exam 2:</label>")
print("    <input type='number' id='midterm2' name='midterm2' step='0.01' required><br>")
print("    <label for='final'>Final Exam:</label>")
print("    <input type='number' id='final' name='final' step='0.01' required><br>")
print("    <input type='submit' value='Add Student'>")
print("</form>")
print("<h2>Student Records</h2>")
print("<table border='1'>")
print("    <tr>")
print("        <th>Student Name</th>")
print("        <th>Average Score</th>")
print("        <th>Delete</th>")
print("    </tr>")
print("</table>")
print("</body>")
print("</html>")
