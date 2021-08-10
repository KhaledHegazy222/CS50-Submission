
Select  movies.title  FROM
movies JOIN ratings
On movies.id = ratings.movie_id
WHERE id IN(

    Select stars.movie_id  FROM
    people JOIN stars
    ON people.id = stars.person_id
    Where name = "Chadwick Boseman"

)
ORDER BY rating DESC LIMIT 5;

