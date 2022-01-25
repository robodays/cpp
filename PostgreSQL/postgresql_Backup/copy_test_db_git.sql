--
-- PostgreSQL database dump
--

-- Dumped from database version 14.1
-- Dumped by pg_dump version 14.1

-- Started on 2022-01-25 02:58:42

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 210 (class 1259 OID 16396)
-- Name: categories; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.categories (
    categories_id integer NOT NULL,
    categories_name character varying(100) NOT NULL
);


ALTER TABLE public.categories OWNER TO postgres;

--
-- TOC entry 209 (class 1259 OID 16395)
-- Name: categories_categories_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.categories ALTER COLUMN categories_id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.categories_categories_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- TOC entry 212 (class 1259 OID 16402)
-- Name: goods; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.goods (
    product_id integer NOT NULL,
    product_name character varying(100) NOT NULL,
    category integer DEFAULT 1 NOT NULL,
    price numeric(18,2)
);


ALTER TABLE public.goods OWNER TO postgres;

--
-- TOC entry 211 (class 1259 OID 16401)
-- Name: goods_product_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

ALTER TABLE public.goods ALTER COLUMN product_id ADD GENERATED ALWAYS AS IDENTITY (
    SEQUENCE NAME public.goods_product_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1
);


--
-- TOC entry 3315 (class 0 OID 16396)
-- Dependencies: 210
-- Data for Name: categories; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.categories (categories_id, categories_name) OVERRIDING SYSTEM VALUE VALUES (2, 'Одежда');
INSERT INTO public.categories (categories_id, categories_name) OVERRIDING SYSTEM VALUE VALUES (3, 'Продукты');
INSERT INTO public.categories (categories_id, categories_name) OVERRIDING SYSTEM VALUE VALUES (4, 'Автозапчасти');
INSERT INTO public.categories (categories_id, categories_name) OVERRIDING SYSTEM VALUE VALUES (1, 'Другое');


--
-- TOC entry 3317 (class 0 OID 16402)
-- Dependencies: 212
-- Data for Name: goods; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (1, 'Детское питание NAN1', 1, 255.45);
INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (2, 'Колесо', 4, 1000.00);
INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (3, 'Мясо Свинина', 3, 500.00);
INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (4, 'Макороны', 3, 45.20);
INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (5, 'Хлеб', 3, 22.50);
INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (6, 'Капот', 4, 3400.00);
INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (8, 'Коляска детская', 1, 10500.00);
INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (9, 'Шампур', 1, 15.50);
INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (10, 'Костюм мужской', 2, 2220.00);
INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (11, 'Носки', 2, 30.50);
INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (12, 'Юбка', 2, 550.00);
INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (7, 'Тосол', 4, 750.00);
INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (13, 'Соль', 3, 222.44);
INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (14, 'Мёд', 3, 233.55);
INSERT INTO public.goods (product_id, product_name, category, price) OVERRIDING SYSTEM VALUE VALUES (15, 'Лук', 3, 233.55);


--
-- TOC entry 3323 (class 0 OID 0)
-- Dependencies: 209
-- Name: categories_categories_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.categories_categories_id_seq', 4, true);


--
-- TOC entry 3324 (class 0 OID 0)
-- Dependencies: 211
-- Name: goods_product_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.goods_product_id_seq', 15, true);


--
-- TOC entry 3171 (class 2606 OID 16400)
-- Name: categories categories_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.categories
    ADD CONSTRAINT categories_pkey PRIMARY KEY (categories_id);


--
-- TOC entry 3173 (class 2606 OID 16406)
-- Name: goods goods_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.goods
    ADD CONSTRAINT goods_pkey PRIMARY KEY (product_id);


--
-- TOC entry 3174 (class 2606 OID 16408)
-- Name: goods fk_category_goods; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.goods
    ADD CONSTRAINT fk_category_goods FOREIGN KEY (category) REFERENCES public.categories(categories_id) NOT VALID;


-- Completed on 2022-01-25 02:58:42

--
-- PostgreSQL database dump complete
--

