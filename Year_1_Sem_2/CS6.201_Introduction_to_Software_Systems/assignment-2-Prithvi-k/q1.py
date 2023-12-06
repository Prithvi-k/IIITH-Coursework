import csv
import time
import requests
from bs4 import BeautifulSoup
import re
import pandas as pd
import matplotlib.pyplot as plt

url_basic = 'https://www.imdb.com/list/ls098063263/?st_dt=&mode=detail&page={}&sort=list_order,asc'

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3'
}

with open('q1text.csv', 'w', newline='', encoding='utf-8') as f:
    writer = csv.writer(f)

    # Write header row
    writer.writerow(['Genre', 'Movie', 'Release Year',
                    'Rating', 'Runtime', 'Gross'])

    for page in range(1, 11):
        url = url_basic.format(page)
        response = requests.get(url, headers=headers)
        time.sleep(1)
        soup = BeautifulSoup(response.text, 'html.parser')

        table = soup.find('div', {'class': 'lister-list'})
        rows = table.find_all('div', {'class': 'lister-item mode-detail'})

        genre_dict = {}
        gross_dict = {}

        # Loop through each row and extract the movie information
        for row in rows:
            movie = row.h3.a.text
            release_year_element = row.find(
                'span', {'class': 'lister-item-year text-muted unbold'})
            release_year = re.search(
                '\d{4}', release_year_element.text).group()
            genre = row.find('span', {'class': 'genre'}).text.strip()
            rating = row.find(
                'span', {'class': 'ipl-rating-star__rating'}).text.strip()
            runtime = row.find(
                'span', {'class': 'runtime'}).text.strip().replace('min', '')
            gross_html = row.find('b')
            gross = gross_html.text.strip().replace('$', '').replace(',', '')
            writer.writerow(
                [genre, movie, release_year, rating, runtime, gross])

df = pd.read_csv('q1text.csv')

# Split genres for each movie and create a new column with list of unique genres
df['Unique Genres'] = df['Genre'].apply(lambda x: list(set(x.split(', '))))

# Explode the unique genres into separate rows
# Creates new rows for each genres
# Copies the rest of columns' data
df = df.explode('Unique Genres')

# Plot the frequency of movies by unique genre
counts = df.groupby('Unique Genres').size()

plt.bar(counts.index, counts.values)
plt.ylim(0, max(counts.values) + 10)
plt.xlabel('Genre')
plt.ylabel('Number of Movies')
plt.title('Frequency of Movies by Unique Genre')
plt.xticks(rotation=90)
plt.tight_layout()
plt.savefig('graph1.png')
# If we need to see output
plt.show()

df2 = pd.read_csv('q1text.csv')

# Sort the dataframe by gross value
top_100 = df2.sort_values(by=['Gross'], ascending=False).head(100)

# plt.plot(top_100['Movie'] + ' (' + top_100['Release Year'].astype(str) + ')', top_100['Gross'] / 1000000000)
# plt.xticks(rotation=90)
plt.plot(range(1, 101), top_100['Gross'] / 1000000000)
plt.xlabel('Rank')
plt.ylabel('Gross Value ($ billion)')
plt.title('Top 100 Movies by Gross Value')
plt.savefig('graph2.png')
# If we need to see output
plt.show()
