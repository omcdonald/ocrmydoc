CREATE TABLE fax
    (
     id          INT         AUTO_INCREMENT
    ,png_path    VARCHAR(64) NOT NULL
    ,tiff_path   VARCHAR(64) NOT NULL
    
    ,PRIMARY KEY(id)
    );

CREATE TABLE element
    (
     id          INT         AUTO_INCREMENT
    ,fax_id      INT         NOT NULL
    ,name        VARCHAR(64) NOT NULL
    ,contents    MEDIUMTEXT
    
    ,PRIMARY KEY(id)
    ,FOREIGN KEY(fax_id) REFERENCES fax
        ON DELETE CASCADE
    );

CREATE TABLE template
    (
     id          INT         AUTO_INCREMENT
    ,name        VARCHAR(64) NOT NULL
    
    ,PRIMARY KEY(id)
    );

CREATE TABLE region
    (
     id          INT         AUTO_INCREMENT
    ,template_id INT         NOT NULL
    ,name        VARCHAR(64)
    ,x           INT         NOT NULL
    ,y           INT         NOT NULL
    ,w           INT         NOT NULL
    ,h           INT         NOT NULL
    
    ,PRIMARY KEY(id)
    ,FOREIGN KEY(template_id) REFERENCES template
        ON DELETE CASCADE
    );
