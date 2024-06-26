-- 코드를 입력하세요
SELECT 
    F.CATEGORY,
    F.PRICE AS MAX_PRICE,
    F.PRODUCT_NAME
FROM
    FOOD_PRODUCT AS F
WHERE
    F.PRICE IN (SELECT MAX(PRICE)
                FROM FOOD_PRODUCT
                GROUP BY CATEGORY)
    AND F.CATEGORY IN ('과자', '국', '김치', '식용유')
ORDER BY MAX_PRICE DESC