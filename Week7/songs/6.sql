SELECT name from songs WHERE artist_id=(SELECT id FROM artists WHERE name='Post Malone');
