<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Check if form fields are set
    if (isset($_POST["fname"]) && isset($_POST["lname"]) && isset($_POST["company"]) && isset($_POST["email"]) && isset($_POST["comment"])) {
        $fname = $_POST["fname"];
        $lname = $_POST["lname"];
        $company = $_POST["company"];
        $email = $_POST["email"];
        $message = $_POST["comment"];
        
        // Validate the email address
        if (filter_var($email, FILTER_VALIDATE_EMAIL)) {
            // Compose and send an email
            $to = "ujoshua368@gmail.com";
            $subject = "New Contact Form Submission";
            $messageBody = "First Name: $fname\nLast Name: $lname\nCompany: $company\nEmail: $email\nMessage:\n$message";
            
            // Additional headers
            $headers = "From: $fname $lname <$email>\r\n";
            
            // Set the content type to plain text
            $headers .= "Content-Type: text/plain; charset=UTF-8\r\n";
            
            // Send the email
            if (mail($to, $subject, $messageBody, $headers)) {
                echo "Your message has been sent successfully.";
            } else {
                echo "Sorry, there was an error sending your message.";
            }
        } else {
            echo "Invalid email address.";
        }
    } else {
        echo "Please fill out all required fields.";
    }
}
?>
