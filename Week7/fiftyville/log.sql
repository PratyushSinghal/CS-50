-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street';

-- Bakery Witness
SELECT transcript FROM interviews
WHERE month = 7 AND day = 28
AND transcript LIKE '%bakery%';

--Ruth
SELECT * FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28
AND hour = 10 AND minute BETWEEN 15 AND 25;

--Check License Plates
SELECT p.name, bak.activity, bak.license_plate, bak.year, bak.month, bak.day, bak.hour, bak.minute
FROM bakery_security_logs bak
JOIN people p ON p.license_plate = bak.license_plate
WHERE bak.year = 2021 AND bak.month = 7 AND bak.day = 28 AND bak.hour = 10 AND bak.minute BETWEEN 15 AND 25;

--Eugene: ATM
SELECT * FROM atm_transactions
WHERE atm_location = 'Leggett Street'
AND year = 2021 AND month = 7 AND day = 28;

SELECT a.*, p.name FROM atm_transactions a
JOIN bank_accounts b ON a.account_number = b.account_number
JOIN people p ON b.person_id = p.id
WHERE a.atm_location = 'Leggett Street' AND a.year = 2021 AND a.month=7 AND a.day - 28
AND a.transaction_type = 'withdraw';

--Raymond: Phone Call
SELECT p.name, ph_ca.caller, ph_ca.receiver, ph_ca.year, ph_ca.month, ph_ca.day, ph_ca.duration
FROM phone_calls ph_ca
JOIN people p ON ph_ca.caller = p.phone_number
WHERE ph_ca.year = 2021 AND ph_ca.month = 7 AND ph_ca.day = 28 AND ph_ca.duration < 60;

--Airports
SELECT * FROM airports
WHERE city = 'Fiftyville';

SELECT f.*, origin.full_name AS origin_airport, destination.full_name AS destination_airport
FROM flights f
JOIN airports origin ON f.origin_airport_id = origin.id
JOIN airports destination ON f.destination_airport_id = destination.id
WHERE origin.id = 8 AND f.year = 2021 AND f.month = 7 AND f.day = 29
ORDER BY f.hour, f.minute;

--Finding Partner in Crime
SELECT p2.name AS receiv
FROM phone_calls pc
JOIN people p1 ON pc.caller = p1.phone_number
JOIN people p2 ON pc.receiv = p2.phone_number
WHERE p1.name = 'Bruce' AND pc.year = 2021 AND pc.month = 7 AND pc.day = 28 AND pc.duration ‹ 60;
