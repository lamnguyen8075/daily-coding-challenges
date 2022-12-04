
- Start Starbucks API and testing on POSTMAN
![Screen Shot 2022-12-03 at 2 52 23 PM](https://user-images.githubusercontent.com/48584294/205465442-2d0336e3-568d-4e59-92c0-088412755772.png)

- Test API: Generate a new starbucks card
![Screen Shot 2022-12-03 at 2 54 05 PM](https://user-images.githubusercontent.com/48584294/205465492-3aea3ced-782d-4c2c-9418-31a4edaa7839.png)

--------------
POSTMAN
- Already imported the JSON script into POSTMAN for API testing

--------------
STARBUCKS NODEJS
- The goal is to rewrite the starbucks-nodejs into Spring MVC
- Don't forget to update the api_endpoint when you deploy on GKE

--------------
STARBUCKS APP
- No need to modify the code of the app
- {login} shortcut to login without typing the PIN
- when you want to run it, run-spring to pass all the api information including the (url,key, reg) in order for the API connec to the app. 


--------------
EXPECTATION
- Adding the feature to let user pick what they one and add into the order then it will deduct the money of the order into the card. 
- Currently in the nodeJS app, It's using H2 DB and you have to switch to MySQL
