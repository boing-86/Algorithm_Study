-- 코드를 입력하세요
SELECT 
    I.ANIMAL_ID,
    I.NAME,
    I.SEX_UPON_INTAKE
FROM ANIMAL_INS AS I
WHERE I.NAME IN ('Lucy', 'Ella', 'Pickle', 'Rogan', 'Sabrina', 'Mitty')