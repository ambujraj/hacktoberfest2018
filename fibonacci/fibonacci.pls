DECLARE
  first number := 0;
  second number := 1;
  temp number;
  n number := &results; -- Enter number of results, shows at least 2
  i number;

BEGIN
  dbms_output.put_line('The fibonacci series is:');
  dbms_output.put_line(first);
  dbms_output.put_line(second);

  for i in 3..n
  loop
    temp := first + second;
    first := second;
    second := temp;

    dbms_output.put_line(temp);
  end loop;
END;
