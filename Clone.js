const form = document.getElementById('registrationForm');
const firstName = document.getElementById('firstName');
const lastName = document.getElementById('lastName');
const birthdate = document.getElementById('birthdate');
const email = document.getElementById('email');
const password = document.getElementById('password');

form.addEventListener('submit', function(event){
    event.preventDefault(); // Prevents form submission

    if(validateForm()){
        // Form is valid, you can submit it
        alert('Form submitted successfully!');
    } else {
        // Form is not valid
        alert('Form validation failed');
    }
});

function validateForm() {
    let isValid = true;

    // Validate first name and last name (only alphabets allowed)
    if(!isAlphabetic(firstName.value) || !isAlphabetic(lastName.value)){
        alert('First name and last name should only contain alphabets');
        isValid = false;
    }

    // Validate email format
    if(!isValidEmail(email.value)){
        alert('Please enter a valid email address!');
        isValid = false;
    }

    // Validate password (should be at least 8 characters long)
    if(password.value.length < 8){
        alert('Password should be at least 8 characters long');
        isValid = false;
    }

    return isValid;
}

function isAlphabetic(value) {
    // Check if the value contains only alphabetic characters
    return /^[a-zA-Z]+$/.test(value);
}

function isValidEmail(value) {
    // Simple email validation (checking for @ symbol)
    return value.includes('@');
}
