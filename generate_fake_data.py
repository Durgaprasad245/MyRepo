import pandas as pd
import random
from faker import Faker
from datetime import datetime

fake = Faker()

# Constants
locations = ['New York', 'Chicago', 'Dallas', 'Atlanta', 'Miami']
menu_items = [
    {'item_id': 1, 'name': 'Pepperoni Pizza', 'price': 12.99},
    {'item_id': 2, 'name': 'Cheese Pizza', 'price': 10.99},
    {'item_id': 3, 'name': 'Veggie Pizza', 'price': 11.49},
    {'item_id': 4, 'name': 'Wings', 'price': 8.99},
    {'item_id': 5, 'name': 'Garlic Bread', 'price': 4.99},
]

# Create Customers
customers = []
for i in range(1000):
    customers.append({
        'customer_id': i + 1,
        'age': random.randint(18, 65),
        'loyalty_member': random.choice([True, False]),
        'email': fake.email()
    })
pd.DataFrame(customers).to_csv("data/customers.csv", index=False)

# Create Sales
sales = []
for i in range(5000):
    item = random.choice(menu_items)
    quantity = random.randint(1, 3)
    sales.append({
        'order_id': i + 1,
        'item_id': item['item_id'],
        'customer_id': random.randint(1, 1000),
        'quantity': quantity,
        'price': round(item['price'] * quantity, 2),
        'order_date': fake.date_between(start_date='-6M', end_date='today'),
        'location': random.choice(locations),
        'delivery_time': random.randint(15, 45)
    })
pd.DataFrame(sales).to_csv("data/sales.csv", index=False)

# Create Menu
pd.DataFrame(menu_items).to_csv("data/menu.csv", index=False)

# Create Locations
location_df = pd.DataFrame({'location': locations})
location_df['location_id'] = location_df.index + 1
location_df.to_csv("data/locations.csv", index=False)

# Create Feedback
feedback = []
for i in range(2000):
    feedback.append({
        'order_id': random.randint(1, 5000),
        'customer_id': random.randint(1, 1000),
        'rating': random.randint(1, 5),
        'comments': fake.sentence(nb_words=6)
    })
pd.DataFrame(feedback).to_csv("data/feedback.csv", index=False)

print("✅ All data files saved in the /data folder.")