import sqlite3


class DBclass:
    def __init__(self, path):
        self.path = path
        self.db = sqlite3.connect(self.path)
        self.cur = self.db.cursor()

    def execute(self, query):
        self.cur.execute(query)
        return [i[0] for i in self.cur.description], self.cur.fetchall()


db = DBclass('ipl.db')
cur = db.cur

# 1.1 Print Umpire Names
cur.execute('SELECT Umpire_Name FROM Umpire LIMIT 10')
umpire_names = ', '.join([row[0] for row in cur.fetchall()])
print("Umpire names:", umpire_names)
print()

# 1.2 Print Unique Umpire Countries
cur.execute('SELECT COUNT(DISTINCT Umpire_Country) FROM Umpire')
num_umpire_countries = cur.fetchone()[0]
print("The number of countries the umpires belong to are: ", num_umpire_countries)
print()

# 1.3 Print Venue Names in ascending order
cur.execute('SELECT Venue_Name FROM Venue ORDER BY Venue_Name ASC')
venue_names = ', '.join([row[0] for row in cur.fetchall()])
print("Venue names: ", venue_names)
print()

# 1.4 Print the names of all the Australian players
cur.execute('SELECT Player_Name FROM Player WHERE Country_Name = "5"')
australian_players = ', '.join([row[0] for row in cur.fetchall()])
print("Australian player names: ", australian_players)
print()

# 1.5 number of matches CSK won more than RCB:
cur.execute('SELECT * FROM Team WHERE Team_Name = "Chennai Super Kings"')
csk = cur.fetchall()
csk_id = csk[0][0]
result = cur.execute("""
            SELECT COUNT(*)
            FROM Match
            WHERE Match_Winner = '""" + str(csk_id) + """'""")
csk_wins = result.fetchone()[0]
# print("The number of matches CSK won: ", result.fetchone()[0])

cur.execute('SELECT * FROM Team WHERE Team_Name = "Royal Challengers Bangalore"')
rcb = cur.fetchall()
rcb_id = rcb[0][0]
result = cur.execute("""
            SELECT COUNT(*)
            FROM Match
            WHERE Match_Winner = '""" + str(rcb_id) + """'""")
rcb_wins = result.fetchone()[0]
# print("The number of matches RCB won: ", result.fetchone()[0])
# print(csk_id)
# print(rcb_id)
print("The number of matches CSK won more than RCB: ", csk_wins - rcb_wins)
