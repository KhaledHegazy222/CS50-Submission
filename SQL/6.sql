Select avg(rating) From
movies join ratings
On movies.id = ratings.movie_id
Where year = 2012;