/** @} */
 /**
 * Float to integer calculator
 *
 * This function takes an float input, a factor, an offset, total bits, and pointer to valid
 * it returns a converted integer value
 * or returns the min if less than min, or max if greater than max.
 * If the value is outside the min or max the valid pointer is set to zero.
 */
 uint64_t Float_to_Int(float input, float factor, float offset, uint8_t numBits, uint8_t *valid) {
	if (input > (((1<<numBits)-1)*factor)+offset) {
			*valid = 0;
			return (uint64_t)((1<<numBits)-1);
	}
	else if (input < offset) {
			*valid = 0;
			return 0;
	}
	else {
			*valid = 1;
			return (uint64_t)((input-offset)/factor);
	}
}
