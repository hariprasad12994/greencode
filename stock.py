import requests

# replace the "demo" apikey below with your own key from https://www.alphavantage.co/support/#api-key
stock_list = ["HDFCBANK", "NATIONALUM", "ITC"]
for stock_symbol in stock_list:
    url = f'https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=BSE:{stock_symbol}&apikey=BQM3H54QCV3GPO48'
    r = requests.get(url)
    data = r.json()
    print(data)
