-- 코드를 입력하세요
SELECT
    DISTINCT(P.PRODUCT_CODE), 
    SUM(S.SALES_AMOUNT * P.PRICE) AS SALES

FROM
    PRODUCT AS P
    INNER JOIN OFFLINE_SALE AS S
    ON P.PRODUCT_ID = S.PRODUCT_ID

GROUP BY P.PRODUCT_CODE
ORDER BY SALES DESC, P.PRODUCT_CODE ASC