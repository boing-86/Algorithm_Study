# -- 코드를 입력하세요
SELECT 
    P.PRODUCT_ID,
    P.PRODUCT_NAME,
    SUM(O.AMOUNT * P.PRICE) AS TOTAL_SALES

FROM (SELECT PRODUCT_ID,
            AMOUNT
     FROM FOOD_ORDER
     WHERE DATE_FORMAT(PRODUCE_DATE, '%m') = 5
     ) AS O
     INNER JOIN FOOD_PRODUCT AS P
     ON O.PRODUCT_ID = P.PRODUCT_ID

GROUP BY P.PRODUCT_ID
ORDER BY TOTAL_SALES DESC, P.PRODUCT_ID
