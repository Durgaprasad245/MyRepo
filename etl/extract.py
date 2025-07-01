import pandas as pd

def extract_all():
    customers = pd.read_csv("data/customers.csv")
    menu = pd.read_csv("data/menu.csv")
    locations = pd.read_csv("data/locations.csv")
    sales = pd.read_csv("data/sales.csv")
    feedback = pd.read_csv("data/feedback.csv")
    return customers, menu, locations, sales, feedback

if __name__ == "__main__":
    c, m, l, s, f = extract_all()
    print("✅ Data extracted:", len(s), "sales records")