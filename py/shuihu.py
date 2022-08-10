import requests
import os
from bs4 import BeautifulSoup

def writein(url):
    # print(url)
    r = requests.get(url)
    r.encoding = 'utf-8'
    t = BeautifulSoup(r.text, features = "html.parser")
    # print(t.find_all(class_ = 'dianjiv')[0].find_all('p')[0].string)
    s = "　　" + t.find_all(class_ = 'dianjiv')[0].find_all('p')[0].string[1:]
    title = t.title.string[6:-5].replace(':', '')
    with open(f"{book_name}/{title}.txt", 'w', encoding= 'utf-8') as f:
       f.write(s)
    print(f'downloaded {title}')

root = 'https://www.gushiwen.com'
book_name = '水浒传'
book_url = 'https://www.gushiwen.com/dianji/1031.html'

if not os.path.exists(book_name):
    os.makedirs(book_name)

r = requests.get(book_url)
r.encoding = 'utf-8'
t = BeautifulSoup(r.text, features = "html.parser")
content = t.find_all(class_ = 'dj')[0].find_all('a')

for tag in content:
    # print(tag.get('href'))
    writein(f'{root}' + tag.get('href'))