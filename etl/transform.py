import pandas as pd
from extract import extract_all

def clean_data(customers, menu, locations, sales, feedback):
    # Remove missing values
    customers = customers.dropna()
    sales = sales.dropna()

    # Ensure data types
    customers['loyalty_member'] = customers['loyalty_member'].astype(bool)
    sales['order_date'] = pd.to_datetime(sales['order_date'])

    # Capitalize location names
    sales['location'] = sales['location'].str.title()

    return customers, menu, locations, sales, feedback

if __name__ == "__main__":
    c, m, l, s, f = clean_data(*extract_all())
    print("✅ Cleaned:", len(s), "sales records")
