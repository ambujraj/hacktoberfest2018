export default function validatePhoneNumber(phone_number){
    if(phone_number != null || phone_number.toString().length()==10 ){
        return true;
    }
    return false;
}