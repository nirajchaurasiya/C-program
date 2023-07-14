
// Load all the script when the document model object is loaded
document.addEventListener('DOMContentLoaded', async () => {

    // Getting the html element with the ID
    const data_of_person_1 = document.getElementById('data_of_person_1');
    const data_of_person_2 = document.getElementById('data_of_person_2');
    const submit_button = document.getElementById("submit_data");
    const data_show = document.getElementById('data_show');
    const total_score_elem = document.getElementById('total_score_elem');
    // getting all persons' data
    const response = await fetch("/user.json");
    const userss = await response.json();

    // Assign total score

    let total_score = 0

    // Function to appendChild
    function appendChildFunction(random_user_position) {
        let single_User = userss[random_user_position]
        let user_data = `
    <div class="user_data">
        <p>Name: ${single_User.name}</p>
        <p>From : ${single_User.live}</p>
        <p>A ${single_User.description}</p>
    </div>
    `
        return user_data;
    }

    function compare_input_value(input_value, random_user_1_position, random_user_2_position) {
        const user_1_follower = random_user_1_position.follower_count
        const user_2_follower = random_user_2_position.follower_count
        const guess = parseInt(input_value)
        console.log(user_1_follower, user_2_follower)
        if (user_1_follower < user_2_follower) {
            console.log("user_1_follower user_2_follower");
            if (guess === 1) {
                return false
            }
            else {
                return true
            }
        }
        else {
            console.log("user_1_follower not user_2_follower");
            if (guess === 1) {
                return true
            } else {
                return false;
            }
        }

    }

    // Generating random number to show it to web
    let random_user_1 = Math.floor(Math.random() * userss.length);
    let random_user_2 = Math.floor(Math.random() * userss.length);

    // Append user_data_1
    let user1 = appendChildFunction(random_user_1);
    data_of_person_1.insertAdjacentHTML('beforeend', user1)

    // Append user_data_2
    let user2 = appendChildFunction(random_user_2);
    data_of_person_2.insertAdjacentHTML('beforeend', user2)


    // Button to randomize the data and update it to web dynamically
    submit_button.addEventListener('click', async (e) => {

        // Getting the value of the user from the input field
        const input_value = document.getElementById('user_input_number').value;

        // Abandon the page from getting reload when the form button is pressed
        e.preventDefault();


        // Generating random number for person 2


        let continue_flag = true;

        while (continue_flag) {

            // Generating random number for person 1
            let random_user_1 = random_user_2;
            // Generating random number for person 2
            random_user_2 = Math.floor(Math.random() * userss.length);

            while (random_user_1 === random_user_2) {
                random_user_2 = Math.floor(Math.random() * userss.length);
            }

            let follower_count_1 = userss[random_user_1];
            let follower_count_2 = userss[random_user_2];
            console.log(follower_count_1, follower_count_2)
            // To call the function compare_input_value and compare the user value with the follower of the user1 and user2
            let is_correct = compare_input_value(input_value, follower_count_1, follower_count_2);
            console.log(random_user_1, random_user_2);

            console.log("is Correct", is_correct)
            if (is_correct) {
                console.log("is Correct under", is_correct)
                total_score += 1
                total_score_elem.textContent = total_score
                // Append user_data_1
                let user1 = appendChildFunction(random_user_1);
                // Reseting th data
                data_of_person_1.innerHTML = ''
                data_of_person_1.insertAdjacentHTML('beforeend', user1)

                // // Append user_data_2
                let user2 = appendChildFunction(random_user_2);
                // Reseting th data
                data_of_person_2.innerHTML = ''
                data_of_person_2.insertAdjacentHTML('beforeend', user2)
            } else {
                continue_flag = false;
                const else_statement =
                    `
    <div class="total_score">
        <h2>
            You Loose.
        </h2>
        <p> ${userss[random_user_2].name} has greater follower i.e. ${userss[random_user_2].follower_count} than ${userss[random_user_1].name} i.e. ${userss[random_user_1].follower_count} </p>
        <p>
            Your total score is ${total_score}
        </p>
    </div>
    `
                data_show.innerHTML = ''
                if (userss[random_user_2].follower_count > userss[random_user_1].follower_count) {
                    data_show.insertAdjacentHTML('beforeend', else_statement);
                } else {
                    data_show.insertAdjacentHTML('beforeend', `
                    <div class="total_score">
                        <h2>
                            You Loose. 
                        </h2>
                        <p> ${userss[random_user_2].name} has less follower i.e. ${userss[random_user_2].follower_count} than ${userss[random_user_1].name} i.e. ${userss[random_user_1].follower_count} </p>
                        <p>
                            Your total score is ${total_score}
                        </p>
                    </div>
                    `);
                }
            }
        }
    })
})