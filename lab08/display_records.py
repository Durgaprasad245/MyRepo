#!/usr/bin/env python3

import cgi
import cgitb
import mysql.connector

# Enable debugging to view errors on the web page
cgitb.enable()

print("Content-type: text/html\n")

# Connect to the database
db_host = "localhost"
db_user = "admin"
db_password = "admin"
db_name = "student_grades"

conn = mysql.connector.connect(host=db_host, user=db_user, password=db_password, database=db_name)
cursor = conn.cursor()

# Retrieve student records from the table
sql = "SELECT * FROM student_records"
cursor.execute(sql)

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

for row in cursor.fetchall():
    id, name, midterm1, midterm2, final = row
    average_score = (midterm1 + midterm2 + 2 * final) / 4
    print("    <tr>")
    print(f"        <td>{name}</td>")
    print(f"        <td>{average_score:.2f}</td>")
    print(f"        <td><a href='delete.py?id={id}'>Delete</a></td>")
    print("    </tr>")

print("</table>")
print("</body>")
print("</html>")

cursor.close()
conn.close()
