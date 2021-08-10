SELECT title from movies where id  IN(


         SELECT stars.movie_id FROM
         stars JOIN people
         ON stars.person_id = people.id
         WHERE name =  "Johnny Depp"
         
         
         And stars.movie_id IN (
            SELECT stars.movie_id FROM
            stars JOIN people
            ON stars.person_id = people.id
            WHERE name =  "Helena Bonham Carter"
         )


);

