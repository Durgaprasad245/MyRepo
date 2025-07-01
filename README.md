# 🍕 Pizza Pulse – End-to-End Data Engineering Project

Sanpeggio’s Pizza is going data-driven! This project builds a complete analytics platform using Python, PostgreSQL, and Power BI to support business insights.

---

## Tech Stack

- Data Generation: Python (Faker, Pandas)  
- ETL: Python (Pandas, SQLAlchemy)  
- Data Warehouse: PostgreSQL  
- Transformations: SQL Views  
- BI Dashboard: Power BI

---

## Project Structure

```

pizza-pulse-data-platform/
├── data/                    # Sample generated CSV files
├── db/                      # SQL schema and transformations
├── etl/                     # ETL scripts
├── PowerBI/                 # Power BI dashboard PDF
├── .gitignore
├── README.md
├── generate\_fake\_data.py
├── requirements.txt

```

---

## Power BI Dashboard

Download the Power BI dashboard PDF to explore the interactive report:

[Power BI Dashboard PDF](./PowerBI/PizzaPulseDashboard.pdf)

---

## How to Run

1. Clone the repo:  
   `git clone https://github.com/Durgaprasad245/MyRepo.git`  
   `cd MyRepo`

2. Set up and activate a Python virtual environment:  
   `python -m venv venv`  
   `venv\Scripts\activate` (Windows) or `source venv/bin/activate` (Mac/Linux)

3. Install dependencies:  
   `pip install -r requirements.txt`

4. Generate sample data:  
   `python generate_fake_data.py`

5. Set up PostgreSQL database and run schema:  
   Create database `pizzapulse`  
   Run `db/create_tables.sql` via psql or a GUI

6. Run ETL pipeline:  
   `python etl/load.py`

7. Apply SQL transformations:  
   Run `db/transformations.sql`

8. Open and refresh the Power BI dashboard PDF in Power BI Desktop.

---

## Author

Durga Prasad Nuthalapati  
Data Engineer | Cloud & Analytics
