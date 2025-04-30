% Define symbolic variables
syms x1 x2 x3 x4 U t m g l J k B Kt ke R L T x1d x1dotd x1ddotd

% Define the state vector
x = [x1; x2; x3; x4];

% Define the system dynamics
x1dot = x2;
x2dot = (-m*g*l/J)*sin(x1) + (l/J)*k*x3^2;
x3dot = (-B/J)*x3 + (Kt/J)*x4 - T/J;
x4dot = (-ke/L)*x3 - (R/L)*x4 + (1/L)*U;

% Define the desired trajectory and its derivatives
z1 = x1 - x1d;
z2 = x2 + c1*z1 - x1dotd;
beta = (J/(l*k))*((m*g*l/J)*sin(x1) + c1^2*z1 + x1ddotd - c1*z2 - c2*z2);
z3 = x3 - sqrt(beta);
alpha3 = (J/Kt)*((B/J)*(sqrt(beta)+z3) + T/J + (1/2)*(beta^(-1/2))*((J/(l*k))*((m*g*l/J)*cos(x1)*x2 + c1^2*(x2-x1dotd) - c1*(-c1*(x2-x1dotd)+(-c1*x2+x1dotd+x1ddotd)) - c2*(-c1*(x2-x1dotd)+(-c1*x2+x1dotd+x1ddotd)))) - c3*(x3-sqrt(beta)));
alpha3dot=(1/Kt)*((B)*(x3) + T + (1/2)*(beta^(-1/2))*((J/(l*k))*((m*g*l/J)*cos(x1)*x2 + c1^2*(x2-x1dotd) - c1*(-c1*(x2-x1dotd)+(-c1*x2+x1dotd+x1ddotd)) - c2*(-c1*(x2-x1dotd)+(-c1*x2+x1dotd+x1ddotd)))) - c3*(x3-sqrt(beta)));

U = L*((ke/L)*(x3) + (R/L)*(x4) + alpha3dot - c4*(x4-alpha3));

% Display the symbolic equations
disp('x1dot ='); disp(x1dot);
disp('x2dot ='); disp(x2dot);
disp('x3dot ='); disp(x3dot);
disp('x4dot ='); disp(x4dot);
disp('U ='); disp(U);
disp('beta=');disp(beta);
disp('alpha3=');disp(alpha3);
disp('alpha3dot=');disp(alpha3dot);

% You can further manipulate these symbolic expressions using
% functions like simplify(), expand(), etc.
x2dot_simplified = simplify(x2dot);
disp('Simplified x2dot ='); disp(x2dot_simplified);

U_simplified=simplify(U);
disp('Simplified U ='); disp(U_simplified);