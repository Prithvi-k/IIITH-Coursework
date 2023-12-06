from flask import Flask, render_template, make_response
import matplotlib.pyplot as plt
import io
import base64
from matplotlib.backends.backend_agg import FigureCanvasAgg as FigureCanvas
from matplotlib.figure import Figure
from io import BytesIO


def last_10_lines():
    with open('templates/data.csv', 'r') as file:
        # Read all lines from the file
        lines = file.readlines()

        # Extract the last 10 lines
        last_10 = lines[-10:]

        return last_10

import csv
import requests
import time
from IPython.display import clear_output

app = Flask(__name__,static_folder='static')

@app.route('/pres_data')
def pres_data():
    if plt.gcf().number > 0:
        plt.close()
    lines=last_10_lines()
    pres=[]
    time=[]
    i=0
    for l in lines:
        fields=l.split(',') 
        pres.append(fields[2])
        time.append(i)
        i+=1
    plt.figure(facecolor='black')
    plt.xlabel('Timestamps',color='white')
    plt.ylabel('Pressure',color='white',labelpad=40)
    ax = plt.axes()
    ax.spines['bottom'].set_color('white')
    ax.spines['left'].set_color('white')
    ax.set_facecolor("black")
    plt.plot(time,pres,color='orange',marker="o")
    plt.tick_params(axis='x', colors='white')
    plt.tick_params(axis='y', colors='white')
    plt.subplots_adjust(left=0.20, bottom=0.15, right=0.9, top=0.9)

    # Convert plot to PNG image
    image = io.BytesIO()
    plt.savefig(image, format='png')
    image.seek(0)
    plot_url = base64.b64encode(image.getvalue()).decode()
    
    # Create a response containing the image

    # Render HTML template with the plot
    return render_template('pres.html', plot_url=plot_url)

@app.route('/datacsv')
def datacsv():
    return render_template('data.csv')

@app.route('/')
def index():
    return render_template('home.html')
   

@app.route('/temp_data')
def temp_data():
    if plt.gcf().number > 0:
        plt.close()
    lines=last_10_lines()
    temp=[]
    time=[]
    i=0
    for l in lines:
        fields=l.split(',') 
        temp.append(fields[5])
        time.append(i)
        i+=1
    plt.figure(facecolor='black')
    plt.xlabel('Timestamps',color='white')
    plt.ylabel('Pressure',color='white',labelpad=40)
    ax = plt.axes()
    ax.spines['bottom'].set_color('white')
    ax.spines['left'].set_color('white')
    ax.set_facecolor("black")
    plt.plot(time,temp,color='orange',marker="o")
    plt.tick_params(axis='x', colors='white')
    plt.tick_params(axis='y', colors='white')
    plt.subplots_adjust(left=0.20, bottom=0.15, right=0.9, top=0.9)


    image = io.BytesIO()
    plt.savefig(image, format='png')
    image.seek(0)
    plot_url1 = base64.b64encode(image.getvalue()).decode()

    # Render HTML template with the plot
    return render_template('temp.html', plot_url=plot_url1)

# @app.route('/pres_data')
# def pres_data():
#     return render_template('pres.html')

@app.route('/hum_data')
def hum_data():
    if plt.gcf().number > 0:
        plt.close()
    lines=last_10_lines()
    hum=[]
    time=[]
    i=0
    for l in lines:
        fields=l.split(',') 
        hum.append(fields[5])
        time.append(i)
        i+=1
    plt.figure(facecolor='black')
    plt.xlabel('Timestamps',color='white')
    plt.ylabel('Pressure',color='white',labelpad=40)
    ax = plt.axes()
    ax.spines['bottom'].set_color('white')
    ax.spines['left'].set_color('white')
    ax.set_facecolor("black")
    plt.plot(time,hum,color='orange',marker="o")
    plt.tick_params(axis='x', colors='white')
    plt.tick_params(axis='y', colors='white')
    plt.subplots_adjust(left=0.20, bottom=0.15, right=0.9, top=0.9)


    image = io.BytesIO()
    plt.savefig(image, format='png')
    image.seek(0)
    plot_url = base64.b64encode(image.getvalue()).decode()

    # Render HTML template with the plot
    return render_template('humidity.html', plot_url=plot_url)

@app.route('/alt_data')
def alt_data():
    if plt.gcf().number > 0:
        plt.close()
    lines=last_10_lines()
    alt=[]
    time=[]
    i=0
    for l in lines:
        fields=l.split(',') 
        alt.append(fields[6])
        time.append(i)
        i+=1
    plt.figure(facecolor='black')
    plt.xlabel('Timestamps',color='white')
    plt.ylabel('Pressure',color='white',labelpad=40)
    ax = plt.axes()
    ax.spines['bottom'].set_color('white')
    ax.spines['left'].set_color('white')
    ax.set_facecolor("black")
    plt.plot(time,alt,color='orange',marker="o")
    plt.tick_params(axis='x', colors='white')
    plt.tick_params(axis='y', colors='white')
    plt.subplots_adjust(left=0.20, bottom=0.15, right=0.9, top=0.9)

    # Convert plot to PNG image
    image = io.BytesIO()
    plt.savefig(image, format='png')
    image.seek(0)
    plot_url = base64.b64encode(image.getvalue()).decode()

    # Render HTML template with the plot
    return render_template('alt.html', plot_url=plot_url)
   

@app.route('/Voltagedata')
def Voltagedata():
    return render_template('Voltagedata.html')

@app.route('/Currentdata')
def Currentdata():
    return render_template('Currentdata.html')

@app.route('/pastdata')
def pastdata():
    return render_template('pastdata.html')

@app.route('/panelState')
def panelState():
    return render_template('panelState.html')




if __name__ == '__main__':
    app.run()


