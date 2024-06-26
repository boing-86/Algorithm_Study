# -- 코드를 입력하세요
SELECT
    AP.APNT_NO AS APNT_NO,
    P.PT_NAME AS PT_NAME,
    P.PT_NO AS PT_NO,
    D.MCDP_CD AS MCDP_CD,
    D.DR_NAME AS DR_NAME,
    AP.APNT_YMD

FROM
    (SELECT 
        APNT_NO,
        PT_NO,
        MDDR_ID,
        APNT_YMD
    FROM 
        APPOINTMENT
    WHERE
        DATE_FORMAT(APNT_YMD, '%Y-%m-%d') = '2022-04-13'
        AND MCDP_CD = 'CS'
        AND APNT_CNCL_YN = 'N'
    ) AS AP
    INNER JOIN PATIENT AS P
    ON AP.PT_NO = P.PT_NO
    INNER JOIN DOCTOR AS D
    ON AP.MDDR_ID = D.DR_ID
    
ORDER BY AP.APNT_YMD ASC