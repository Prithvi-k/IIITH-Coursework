// Confirm funciton which promts a user to enter an otp and then sends it to the flask server
function confirm() {
    var otp = prompt("Please enter your OTP", "");
    if (otp != null) {
        $.ajax({
            url: '/confirm',
            data: {otp: otp},
            type: 'POST',
            success: function(response) {
                alert(response);
            },
            error: function(error) {
                console.log(error);
            }
        });
    }
}