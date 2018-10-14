/*\
|*| NodeJS Guessing Game Code
|*| @author William Zhou (https://github.com/wzhouwzhou)
\*/

const { createInterface } = require('readline');

const rl = createInterface({
  input: process.stdin,
  output: process.stdout,
});

let meta;

const validate = _input => {
  const input = `${_input}`.trim();
  if (input === 'STOP') meta.signal = true;
  if (meta.signal) {
    rl.removeListener('line', validate);
    console.log(meta.thankyou);
    process.exit(0);
  }
  const num = parseInt(+input);
  if (isNaN(num)) return console.log(meta.instructions);
  if (num === meta.current_num) {
    console.log(meta.correct());
    meta.counter = 0;
    return meta.gen_guess();
  } else {
    ++meta.counter;
    console.log(meta.incorrect(num, meta.current_num));
  }
};

rl.on('line', validate);

(meta = {
  instructions: 'Please type a number, or "STOP" to quit.',
  correct: () => `You guessed it in ${meta.counter} tries! A new number has been generated. ${meta.instructions}`,
  incorrect: (num, answer) => `Your guess was too ${num > answer ? 'high' : 'low'}`,
  signal: false,
  counter: 1,
  gen_guess: () => meta.current_num = ~~(100 * Math.random()),
  start: () => (meta.gen_guess(), console.log(meta.instructions)),
  thankyou: 'Thank you for playing! Brought to you by William Zhou (https://github.com/wzhouwzhou).'
}).start();
