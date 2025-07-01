-- View: Total daily sales per location
CREATE OR REPLACE VIEW daily_sales AS
SELECT
  order_date,
  location,
  COUNT(order_id) AS total_orders,
  SUM(price) AS total_revenue
FROM sales
GROUP BY order_date, location
ORDER BY order_date, location;

-- View: Top 5 best-selling menu items
CREATE OR REPLACE VIEW top_pizzas AS
SELECT
  s.item_id,
  m.name AS item_name,
  SUM(s.quantity) AS total_quantity,
  SUM(s.price) AS total_sales
FROM sales s
JOIN menu m ON s.item_id = m.item_id
GROUP BY s.item_id, m.name
ORDER BY total_quantity DESC
LIMIT 5;

-- View: Delivery time performance by location
CREATE OR REPLACE VIEW delivery_performance AS
SELECT
  location,
  AVG(delivery_time) AS avg_delivery_time,
  MAX(delivery_time) AS max_delivery_time,
  MIN(delivery_time) AS min_delivery_time
FROM sales
GROUP BY location;

-- View: Customer loyalty stats
CREATE OR REPLACE VIEW loyalty_summary AS
SELECT
  loyalty_member,
  COUNT(customer_id) AS customer_count,
  AVG(age) AS avg_age
FROM customers
GROUP BY loyalty_member;

-- View: Feedback summary by rating
CREATE OR REPLACE VIEW feedback_summary AS
SELECT
  rating,
  COUNT(*) AS total_reviews,
  ROUND(AVG(LENGTH(comments)), 2) AS avg_comment_length
FROM feedback
GROUP BY rating
ORDER BY rating DESC;