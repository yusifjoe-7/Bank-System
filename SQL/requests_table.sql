CREATE TABLE create_requests(
    UUID INTAGER PRIMARY KEY,
    username TEXT UNIQUE NOT NULL,
    hashed_password TEXT NOT NULL,
    role INTAGER NOT NULL
);