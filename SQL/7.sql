Select movies.title, ratings.rating From movies JOIN
ratings ON movies.id = ratings.movie_id
Where movies.year = 2010
Order by rating DESC , title ASC LIMIT 800;
