import pandas as pd
from sqlalchemy import create_engine
from dotenv import load_dotenv
import os

def load_to_db(customers, menu, locations, sales, feedback):
    load_dotenv()

    engine = create_engine(
        f"postgresql://{os.getenv('DB_USER')}:{os.getenv('DB_PASSWORD')}@{os.getenv('DB_HOST')}:{os.getenv('DB_PORT')}/{os.getenv('DB_NAME')}"
    )

    customers.to_sql('customers', engine, if_exists='append', index=False)
    menu.to_sql('menu', engine, if_exists='append', index=False)
    locations.to_sql('locations', engine, if_exists='append', index=False)
    sales.to_sql('sales', engine, if_exists='append', index=False)
    feedback.to_sql('feedback', engine, if_exists='append', index=False)

    print("✅ All data loaded into PostgreSQL!")

if __name__ == "__main__":
    from extract import extract_all
    from transform import clean_data

    customers, menu, locations, sales, feedback = clean_data(*extract_all())
    load_to_db(customers, menu, locations, sales, feedback)
