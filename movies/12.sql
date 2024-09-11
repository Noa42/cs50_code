SELECT title FROM movies WHERE id IN (
SELECT movie_id FROM stars
JOIN people
ON stars.person_id = people.id
WHERE name = "Helena Bonham Carter" AND movie_id IN
(SELECT movie_id FROM stars WHERE person_id IN
(SELECT id FROM people WHERE name = "Johnny Depp")
))