import requests
import matplotlib.pyplot as plt
import time
from IPython.display import clear_output

while True:
    clear_output(wait=True)
    url = "http://127.0.0.1:5089/~/in-cse/in-name/SOLAR-OPTIMISATION/Temp/Data?rcn=4"
    payload={}
    headers = {
    'X-M2M-Origin': 'admin:admin',
    'Accept': 'application/json'
    }
    
    response_temp = requests.request("GET", url, headers=headers, data=payload)
    
    print(response_temp.text)
    url = "http://127.0.0.1:5089/~/in-cse/in-name/SOLAR-OPTIMISATION/Pressure/Data?rcn=4"
    response_press =requests.request("GET", url, headers=headers, data=payload)
    url = "http://127.0.0.1:5089/~/in-cse/in-name/SOLAR-OPTIMISATION/Humidity/Data?rcn=4"
    response_humid =requests.request("GET", url, headers=headers, data=payload)
    url = "http://127.0.0.1:5089/~/in-cse/in-name/SOLAR-OPTIMISATION/Current-1/Data?rcn=4"
    response_current1 =requests.request("GET", url, headers=headers, data=payload)
    url = "http://127.0.0.1:5089/~/in-cse/in-name/SOLAR-OPTIMISATION/Current-2/Data?rcn=4"
    response_current2 =requests.request("GET", url, headers=headers, data=payload)
    url = "http://127.0.0.1:5089/~/in-cse/in-name/SOLAR-OPTIMISATION/Voltage-1/Data?rcn=4"
    response_voltage1 =requests.request("GET", url, headers=headers, data=payload)
    url = "http://127.0.0.1:5089/~/in-cse/in-name/SOLAR-OPTIMISATION/Voltage-2/Data?rcn=4"
    response_voltage2 =requests.request("GET", url, headers=headers, data=payload)
    data_temp = eval(response_temp.text)
    data_press = eval(response_press.text)
    data_humid = eval(response_humid.text)
    data_curr1 = eval(response_current1.text)
    data_volt1 = eval(response_voltage1.text)
    data_cons_120_temp = data_temp["m2m:cnt"]["m2m:cin"]
    data_cons_120_press = data_press["m2m:cnt"]["m2m:cin"]
    data_cons_120_humid = data_humid["m2m:cnt"]["m2m:cin"]
    data_cons_120_curr1 = data_curr1["m2m:cnt"]["m2m:cin"]
    data_cons_120_volt1 = data_volt1["m2m:cnt"]["m2m:cin"]
    con_0_temp = data_cons_120_temp[0]["con"]
    con_0_press = data_cons_120_press[0]["con"]
    con_0_humid = data_cons_120_humid[0]["con"]
    con_0_curr1 = data_cons_120_curr1[0]["con"]
    con_0_volt1 = data_cons_120_volt1[0]["con"]
    param_1_list_temp = []
    for content in data_cons_120_temp:
        _temp = eval(content["con"])
        param_1_list_temp += [_temp[2]]
    param_1_list_press = []
    for content in data_cons_120_press:
        _temp = eval(content["con"])
        param_1_list_press += [_temp[2]]
    param_1_list_humid = []
    for content in data_cons_120_humid:
        _temp = eval(content["con"])
        param_1_list_humid += [_temp[2]]
    param_1_list_curr1 = []
    for content in data_cons_120_curr1:
        _temp = eval(content["con"])
        param_1_list_curr1 += [_temp[2]]
    param_1_list_volt1 = []
    for content in data_cons_120_volt1:
        _temp = eval(content["con"])
        param_1_list_volt1 += [_temp[2]]
    plt.plot(param_1_list_temp, label = "temperature")
    plt.plot(param_1_list_press, label = "pressure")
    plt.plot(param_1_list_humid, label = "humidity")
    plt.plot(param_1_list_curr1, label = "current-1")
    plt.plot(param_1_list_volt1, label = "voltage-1")
    plt.legend()
    plt.show()
    time.sleep(1)
 