import requests
import json


url="http://127.0.0.1:5089/~/in-cse/in-name/SOLAR-OPTIMISATION/Temp/Data?rcn=4"
payload={}
headers={
    'X-M2M-Origin':'admin:admin',
    'Accept':'application/json'
}
response=requests.request("GET",url,headers=headers,data=payload)

data=eval(response.text)
data2=data['m2m:cnt']
dataLoad3=data2['m2m:cin']

############################################
# for i in data3:
#     print((i['con']))
# print(type(data3))
    
# url="http://127.0.0.1:5089/~/in-cse/in-name/AE-TEST/Load2/Data?rcn=4"
url="http://127.0.0.1:5089/~/in-cse/in-name/SOLAR-OPTIMISATION/Current-1/Data?rcn=4"
payload={}
headers={
    'X-M2M-Origin':'admin:admin',
    'Accept':'application/json'
}
response=requests.request("GET",url,headers=headers,data=payload)

data=eval(response.text)
data2=data['m2m:cnt']
dataLoad2=data2['m2m:cin']

############################################


url="http://127.0.0.1:5089/~/in-cse/in-name/SOLAR-OPTIMISATION/Voltage-1/Data?rcn=4"
# url="http://127.0.0.1:5089/~/in-cse/in-name/AE-TEST/Load1/Data?rcn=4"
payload={}
headers={
    'X-M2M-Origin':'admin:admin',
    'Accept':'application/json'
}
response=requests.request("GET",url,headers=headers,data=payload)

data=eval(response.text)
data2=data['m2m:cnt']
dataLoad1=data2['m2m:cin']

############################################


# url="http://127.0.0.1:5089/~/in-cse/in-name/AE-TEST/LDR/Data?rcn=4"
url="http://127.0.0.1:5089/~/in-cse/in-name/SOLAR-OPTIMISATION/Altitude/Data?rcn=4"
payload={}
headers={
    'X-M2M-Origin':'admin:admin',
    'Accept':'application/json'
}
response=requests.request("GET",url,headers=headers,data=payload)

data=eval(response.text)
data2=data['m2m:cnt']
dataLDR=data2['m2m:cin']

##########################################

# url="http://127.0.0.1:5089/~/in-cse/in-name/AE-TEST/Solar/Data?rcn=4"
url="http://127.0.0.1:5089/~/in-cse/in-name/SOLAR-OPTIMISATION/Pressure/Data?rcn=4"
payload={}
headers={
    'X-M2M-Origin':'admin:admin',
    'Accept':'application/json'
}
response=requests.request("GET",url,headers=headers,data=payload)

data=eval(response.text)
data2=data['m2m:cnt']
dataSun=data2['m2m:cin']

##########################################

# url="http://127.0.0.1:5089/~/in-cse/in-name/AE-TEST/Conventional/Data?rcn=4"
url="http://127.0.0.1:5089/~/in-cse/in-name/SOLAR-OPTIMISATION/Humidity/Data?rcn=4"
payload={}
headers={
    'X-M2M-Origin':'admin:admin',
    'Accept':'application/json'
}
response=requests.request("GET",url,headers=headers,data=payload)

data=eval(response.text)
data2=data['m2m:cnt']
dataCon1=data2['m2m:cin']

##########################################

# url="http://127.0.0.1:5089/~/in-cse/in-name/AE-TEST/Conventional/Data?rcn=4"
url="http://127.0.0.1:5089/~/in-cse/in-name/SOLAR-OPTIMISATION/Voltage-2/Data?rcn=4"
payload={}
headers={
    'X-M2M-Origin':'admin:admin',
    'Accept':'application/json'
}
response=requests.request("GET",url,headers=headers,data=payload)

data=eval(response.text)
data2=data['m2m:cnt']
dataCon=data2['m2m:cin']
# print((dataCon))


# print((dataSun))
# print((dataLDR))
# print((dataLoad1))
# print((dataLoad2))
# print((dataLoad3))
time=[]
volt1=[]
volt2=[]
curr1=[]
pres=[]
temp=[]
alt=[]
hum=[]
print(len(dataCon))
for i in range(len(dataCon)):
    dCon=(dataCon[i]['con'])
    dSun=(dataSun[i]['con'])
    dL1=(dataLoad1[i]['con'])
    dL2=(dataLoad2[i]['con'])
    dL3=(dataLoad3[i]['con'])
    dLDR=(dataLDR[i]['con'])
    dHum=(dataCon1[i]['con'])
    dL1=dL1.strip('[]').split(',')
    tim=dL1[0].strip()
    dL1=dL1[2].strip()

    dL2=dL2.strip('[]').split(',')
    dL2=dL2[2].strip()

    dL3=dL3.strip('[]').split(',')
    dL3=dL3[2].strip()

    dSun=dSun.strip('[]').split(',')
    dSun=dSun[2].strip()

    dCon=dCon.strip('[]').split(',')
    dCon=dCon[2].strip()

    dHum=dHum.strip('[]').split(',')
    dHum=dHum[2].strip()

    dLDR=dLDR.strip('[]').split(',')
    dLDR=dLDR[2].strip()

    stri=tim+','+dCon+','+dSun+','+dL1+','+dL2+','+dL3+','+dLDR+','+dHum+'\n'

    print(stri)

    with open('data.csv', 'a') as file:
        file.write(stri)
    