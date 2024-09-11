-- Keep a log of any SQL queries you execute as you solve the mystery.

--1 Find the description from crime scenes report
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 and day = 28 AND street = 'Humphrey Street';
-- New info:
--    3 witnesses
--    time: 10:15
--    place: Humphrey Street Bakery

--2 Get info from the interviews naming bakery
SELECT name, transcript FROM interviews WHERE year = 2021 AND month = 7 and day = 28 and transcript LIKE "%bakery%";
--New info:
--   witnesses: Ruth, Eugene, Raymond
--   between 10:15 and 10:15 the thief used the parking
--   before 10:15 the thief was by the ATM on Leggett Street
--   calling for less than a minute at leaving the bakery. The accomplice bought first ticket out day 29.

--3 Parking reserch crossing with people
SELECT name FROM bakery_security_logs
JOIN people ON bakery_security_logs.license_plate = people.license_plate
WHERE year = 2021 AND month = 7  AND day = 28 AND hour = 10 AND minute >=15 AND minute <=25;
-- New info: Suspects(7) Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey

--4 ATM research crossing bank and people
SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street';

--New info: Suspects(4 now, three discarted): Bruce, Luca, Iman, Diana

--5 Callings reasearch crossing with people
SELECT name FROM phone_calls
JOIN people ON phone_calls.caller = people.phone_number
WHERE year = 2021 AND month = 7 AND day = 28 and duration <= 60;
-- New info: Suspects (2 now, 2 discarded): Bruce, Diana

--6 getting the first flight from fiftyville
SELECT * FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
WHERE city = 'Fiftyville' AND year = 2021 AND month = 7 AND day = 29
ORDER BY hour, minute;
--New info: the first flight on 29 is id 36 at 8:20

--7 Passengers from flight 36
SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id = 36;
-- New info: the thief = Bruce!!!

--8 Flight destination
SELECT city FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
WHERE flights.id = 36;
-- New info: the destination was New York City

-- Accomplice suspects because of calling
SELECT name FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE phone_calls.id = (SELECT phone_calls.id FROM phone_calls JOIN people ON phone_calls.caller = people.phone_number WHERE year = 2021 AND month = 7 AND day = 28 AND duration <= 60 AND people.name = 'Bruce');
--New info: the accomplice was Robin