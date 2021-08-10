 -- Select people who were with Kevin Bacon



 Select  DISTINCT name from people Where id IN(


     Select stars.person_id From
     stars join movies
     On stars.movie_id = movies.id
     Where movie_id IN(

         SELECT stars.movie_id from
         stars join people
         On stars.person_id = people.id
         Where name = "Kevin Bacon"
         AND birth = 1958


    )
 )
     AND NOT name = "Kevin Bacon";