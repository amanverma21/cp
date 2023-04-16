# Write your MySQL query statement below
SELECT patient_id, patient_name, conditions
FROM patients
WHERE conditions like '% DIAB1%' or conditions like 'DIAB1%'