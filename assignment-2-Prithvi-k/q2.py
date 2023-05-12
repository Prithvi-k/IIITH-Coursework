import pandas as pd

df = pd.read_csv('q1text.csv')
df = df.sort_values(by=['Rating', 'Runtime'], ascending=[False, True])
columns_to_print = ['Movie', 'Rating', 'Runtime']
print("Top 100 Movies by IMDB Rating")
print(df[columns_to_print].head(100).to_string(index=False))
print()

# Filter the dataframe based on user input
print(".....")
print("Filter Options:")
print("1. Duration")
print("2. IMDB Rating")
print("3. Year of Release")
print("4. Genre")
filter_choice = int(input("Enter choice (1-4): "))

# Filter the dataframe based on user input
if filter_choice == 1:
    # Prompt to enter a duration range
    min_duration, max_duration = map(int, input("Enter range: ").split())
    # Filter dataframe based on duration range
    duration_filtered_df = df[(df['Runtime'] >= min_duration) &
                              (df['Runtime'] <= max_duration)]
    duration_filtered_df = duration_filtered_df.sort_values(by='Runtime')
    # Add a new column with row numbers
    duration_filtered_df['Row Number'] = range(
        1, duration_filtered_df.shape[0] + 1)
    # Desired columns
    columns_to_print = ['Row Number', 'Movie', 'Runtime']
    # Error message if no movies found in the given duration range
    if duration_filtered_df.empty:
        print("\nNo movies found in the given duration range!")
    else:
        print(duration_filtered_df[columns_to_print].to_string(index=False))

elif filter_choice == 2:
    # Prompt to enter an IMDB rating range
    min_rating, max_rating = map(float, input("Enter range: ").split())
    # Filter dataframe based on IMDB rating range
    rating_filtered_df = df[(df['Rating'] >= min_rating) &
                            (df['Rating'] <= max_rating)]
    rating_filtered_df = rating_filtered_df.sort_values(
        by='Rating', ascending=False)
    # Add a new column with row numbers
    rating_filtered_df['Row Number'] = range(
        1, rating_filtered_df.shape[0] + 1)
    # Desired columns
    columns_to_print = ['Row Number', 'Movie', 'Rating']
    # Error message if no movies found in the given IMDB rating range
    if rating_filtered_df.empty:
        print("\nNo movies found in the given IMDB rating range!")
    else:
        print(rating_filtered_df[columns_to_print].to_string(index=False))

elif filter_choice == 3:
    # Prompt to enter a release year range
    min_year, max_year = map(int, input("Enter range: ").split())
    # Filter dataframe based on release year range
    release_year_filtered_df = df[(df['Release Year'].astype(int) >= min_year) &
                                  (df['Release Year'].astype(int) <= max_year)]
    release_year_filtered_df = release_year_filtered_df.sort_values(
        by='Release Year')
    # Add a new column with row numbers
    release_year_filtered_df['Row Number'] = range(
        1, release_year_filtered_df.shape[0] + 1)
    # Desired columns
    columns_to_print = ['Row Number', 'Movie', 'Release Year']
    # Error message if no movies found in the given release year range
    if release_year_filtered_df.empty:
        print("\nNo movies found in the given release year range!")
    else:
        print(release_year_filtered_df[columns_to_print].to_string(
            index=False))

elif filter_choice == 4:
    # Prompt to enter a genre
    genre = input("Enter a genre: ")
    # Filter dataframe based on genre
    filtered_df = df[df['Genre'].str.contains(genre)]
    filtered_df = filtered_df.sort_values(by='Rating', ascending=False)
    # Add a new column with row numbers
    filtered_df['Row Number'] = range(1, filtered_df.shape[0] + 1)
    # Desired columns
    columns_to_print = ['Row Number', 'Movie', 'Rating']
    # Error message if no movies found in the given genre
    if filtered_df.empty:
        print("\nNo movies found in the given genre!")
    else:
        print(f"\nMovies in {genre} genre sorted by IMDB rating:\n")
        print(filtered_df[columns_to_print].to_string(index=False))


# Just a test choice to print all unique genres
elif filter_choice == 5:
    print()
    print("Unique genres:")
    unique_genres = df['Genre'].unique()

    for i in range(len(unique_genres)):
        print(f"{i + 1}. {unique_genres[i]}")

else:
    print("Invalid choice. Please try again.")

print("....")
