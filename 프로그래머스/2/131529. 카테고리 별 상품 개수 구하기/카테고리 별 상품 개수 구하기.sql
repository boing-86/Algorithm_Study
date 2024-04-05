-- 코드를 입력하세요
SELECT
    LEFT(P.PRODUCT_CODE, 2) AS CATEGORY,
    COUNT(LEFT(P.PRODUCT_CODE, 2)) AS PRODUCTS
FROM PRODUCT AS P
GROUP BY (LEFT(P.PRODUCT_CODE, 2))
ORDER BY (LEFT(P.PRODUCT_CODE, 2)) ASC