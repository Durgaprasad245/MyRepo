-- customers table
CREATE TABLE customers (
  customer_id INT PRIMARY KEY,
  age INT,
  loyalty_member BOOLEAN,
  email TEXT
);

-- menu table
CREATE TABLE menu (
  item_id INT PRIMARY KEY,
  name TEXT,
  price NUMERIC
);

-- locations table
CREATE TABLE locations (
  location_id INT PRIMARY KEY,
  location TEXT
);

-- sales table
CREATE TABLE sales (
  order_id INT PRIMARY KEY,
  item_id INT REFERENCES menu(item_id),
  customer_id INT REFERENCES customers(customer_id),
  quantity INT,
  price NUMERIC,
  order_date DATE,
  location TEXT,
  delivery_time INT
);

-- feedback table
CREATE TABLE feedback (
  order_id INT,
  customer_id INT,
  rating INT,
  comments TEXT,
  PRIMARY KEY(order_id, customer_id)
);
