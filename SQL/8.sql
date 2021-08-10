SELECT name FROM people Where id IN
(
SELECT stars.person_id FROM movies JOIN
stars ON movies.id = stars.movie_id
WHERE movies.title = "Toy Story"
);