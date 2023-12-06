from wordcloud import WordCloud
import matplotlib.pyplot as plt

with open('sh.txt', 'r') as f:
    lines = f.readlines()

storyText = ''

for line in lines:
    # Check if the line contains any alphabetic characters
    for c in line:
        line = ''.join(c for c in line if c.isalpha()
                       or c.isspace() or c.isnumeric())
    storyText += line.lower()


# Remove any extra whitespace
storyText = ' '.join(storyText.split())

# print(storyText[:1000])

stopwords = []
with open('stopwords.txt', 'r') as file:
    for line in file:
        if not line.startswith('#'):
            stopwords.append(line.strip())

# print(stopwords)

words = storyText.split()

words = [word for word in words if word.lower() not in stopwords]

text = ' '.join(words)
# print(text)
# print(text[:1000])


countDict = {}

for word in text.split():
    if word not in countDict:
        countDict[word] = 1
    else:
        countDict[word] += 1

sortedCountDict = sorted(countDict.items(), key=lambda x: x[1], reverse=True)

# print(sortedCountDict)
print(
    f"Most common word = {sortedCountDict[0][0]} ({sortedCountDict[0][1]} occurences)")
# print(sortedCountDict)

totalLength = 0
for word in text.split():
    totalLength += len(word)

averageLength = totalLength / len(text.split())

print(
    f"Average word length in the given text (after removing stopwords) is: {averageLength:.2f} characters")

# Generate wordcount from sorted frequency dictionary
wordcountForWordcloud = {}
for word, count in sortedCountDict:
    wordcountForWordcloud[word] = count

# Generate wordcloud from wordcountForWordcloud dictionary
wordcloud = WordCloud(width=600, height=600, background_color='white',
                      min_font_size=10).generate_from_frequencies(wordcountForWordcloud)

plt.figure(figsize=(8, 8))
plt.imshow(wordcloud)
plt.axis('off')
plt.savefig('wordcloud.png')
plt.show()
