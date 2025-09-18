# Object-Oriented Programming (OOP)
**OOP (Object-Oriented Programming)** is a programming paradigm based on the concept of "objects", which can contain data (fields/properties) and code (methods). OOP promotes **modularity, reusability, and maintainability** of code by organizing software into classes and objects.  
- **Class**: A blueprint for creating objects (e.g., Car, Person).

- **Object**: An instance of a class.

### ✅ Benefits of OOP in C#
- Improved code organization.
- Easier maintenance and scalability.
- Promotes modular and reusable code.
- Aligns with real-world modeling.

## 🔑 Four Pillars of OOP in C#
| Concept | Description | C# Implementation |
| --- | --- | --- |
| **Encapsulation** | Hiding internal details and exposing only what’s necessary | Use of `private`, `public`, `internal`, `protected` access modifiers |
| **Abstraction** | Representing essential features without showing background details | Use of `abstract` classes, `interfaces` |
| **Inheritance** | Creating new classes from existing ones to promote code reuse | Use of `:` syntax to inherit from a base class |
| **Polymorphism** | Ability for objects to take many forms, i.e., behave differently in different contexts | Use of method overriding (`virtual`, `override`) or overloading |

## Encapsulation
It refers to the **bundling of data (fields) and methods (functions)** that operate on the data into a single unit (a class), while controlling the access to object's internal state through access modifiers.

### 🎯 Goals of Encapsulation
- **Protect internal state** of an object from unintended or harmful changes.
- **Provide controlled access** through methods or properties (getters/setters).
- **Improve maintainability** and modularity of the code.
- Support **data validation**, consistency, and integrity.

### ✅ Ways C# supports encapsulation:

#### 1. Access Modifiers  
These control the visibility of class members (fields, properties, methods, etc.) from other parts of the code.  
- `private`: Fields or methods are accessible only within the same class. This is the default for fields to hide them from external access.
- `public`: Members are accessible from everywhere. Used for methods that form the public interface.
- `protected`: Members are accessible within the class and its derived classes.
- `internal`: Members are accessible within the same assembly.
- `protected internal`: Members are accessible within the same assembly or derived classes in other assemblies.
- `private protected`: Members are accessible only within the class and derived classes in the same assembly.  

By marking fields as `private` (or similar), you prevent direct external access, a core principle of encapsulation.  

```cs
class Car{
    private int speed; // Cannot be accessed directly outside

    public void SetSpeed(int value){
        if (value >= 0) speed = value;
    }

    public int GetSpeed() {
        return speed;
    }
}

```

#### 2. Properties
C# provides a cleaner syntax using properties with get/set accessors to encapsulate fields while still exposing them safely.  
```cs
class Car {
    private int _speed;

    public int Speed {
        get { return _speed; }
        set {
            if (value >= 0) _speed = value;
        }
    }
}

```
Or using **auto-implemented properties** with access control:
```cs
public class Person
{
    public string Name { get; private set; } // Readable from outside, writable only inside
}

```

#### 3. Methods
Encapsulation often involves exposing functionality through **public methods**, while keeping the implementation **private**.  
```cs
class BankAccount {
    private decimal balance;

    public void Deposit(decimal amount) {
        if (amount > 0) balance += amount;
    }

    public decimal GetBalance() {
        return balance;
    }
}
```

#### 4. Interfaces and Abstraction
While abstraction and encapsulation are distinct, interfaces support encapsulation by hiding the class’s internal details related to implementation.  
```cs
public interface ILogger {
    void Log(string message);
}

public class FileLogger : ILogger {
    private string logFilePath = "log.txt"; // hidden implementation data

    public void Log(string message) {
        // writes to file
    }
}
```

#### 5. Private/Internal Classes and Nested Types
You can restrict access to certain classes entirely by marking them `private` or `internal`.
```cs
public class OuterClass {
    private class InnerHelper {
        public void DoWork() { }
    }
}
```

### Interview Questions
---
#### Q. What is encapsulation in OOP? How is it different from abstraction?
**Encapsulation** in Object-Oriented Programming (OOP) is the bundling of data (attributes) and methods (functions) that operate on that data into a single unit, typically a class, while restricting direct access to some of the object's components. It’s about hiding the internal state of an object and only allowing access through well-defined interfaces, like public methods. This is often achieved using access modifiers (e.g., private, protected, public) to control visibility and ensure data integrity.  
> **Example**: In a `BankAccount` class, the balance is a private attribute. You can only modify it through public methods like `deposit()` or `withdraw()`, which enforce rules (e.g., no negative deposits). This protects the balance from being directly altered in an invalid way.

**Abstraction** in OOP is about hiding complex implementation details and exposing only the essential features of an object to the user. It focuses on *what* an object does, not *how* it does it, often achieved through abstract classes or interfaces.  
> **Example**: A `CoffeeMachine` interface might define a `brew()` method. The user doesn’t need to know the internal mechanics (heating, grinding, etc.)—just that calling `brew()` makes coffee.  

Both concepts work together to make OOP systems modular, secure, and user-friendly, but they address different aspects of design.
- **Purpose**:
   - Encapsulation: Protects an object’s internal state by restricting access and bundling data with methods.
   - Abstraction: Simplifies interaction by hiding complex implementation details and showing only necessary functionality.

- **Focus**:
   - Encapsulation: Focuses on *data security* and bundling.
   - Abstraction: Focuses on *simplifying interaction* and reducing complexity.

**Analogy**:
- Encapsulation is like a locked safe: only specific keys (methods) can access the contents (data).
- Abstraction is like a car’s dashboard: you see simple controls (steering, pedals) without needing to understand the engine’s complexity.

---

#### Q. Why is encapsulation important?
Encapsulation enhances security, data integrity, maintainability, and modularity, making OOP systems more robust and easier to manage.  
> **Example**: In a `User` class, encapsulating a `password` field ensures it can only be modified through a `changePassword()` method that enforces security rules (e.g., minimum length, special characters). This protects the system from invalid or insecure password changes.

---

#### Q. Can you give an example of encapsulation in C#?
- **Private Fields**: The `balance` field is private, preventing direct access from outside the class.
- **Properties**: The `Balance` property provides controlled read/write access with validation. The `AccountHolder` property is read-only after initialization (`init`).
- **Public Methods**: Methods like `Deposit` and `Withdraw` expose functionality while enforcing rules, keeping the internal state consistent.
- **Constructor**: Initializes the object in a valid state, further supporting encapsulation by ensuring proper setup.

---

#### Q. What is the default access modifier for class members in C#? Why is that important for encapsulation?
The default access modifier for class members in C# is `private`. This means that if no access modifier is specified, the member is only accessible within the same class.  
This is important for encapsulation because it ensures that class members are not accessible from outside the class, protecting the internal state of the object and preventing unintended interference.

---


#### Q. How do properties support encapsulation in C#?
Properties in C# are a key mechanism for supporting **encapsulation** by providing controlled access to a class’s private fields while maintaining the principles of data hiding and abstraction. They allow a class to expose its data in a safe, flexible, and maintainable way, combining the benefits of direct field access with the ability to enforce validation, logic, or restrictions.  

**1. Controlled Access to Private Fields:**   
Properties act as an intermediary between a class’s private fields and external code. By keeping fields `private` and exposing them through properties, you prevent direct access to the internal state, ensuring data integrity.  
```cs
public class Person
{
    private string name; // Private field

    // Property to control access to name
    public string Name
    {
        get => name; // Allow reading
        set => name = !string.IsNullOrEmpty(value) ? value : throw new ArgumentException("Name cannot be empty.");
    }
}
```
Here, the `Name` property ensures the `name` field cannot be set to an empty or null value, enforcing validation.  

**2. Hiding Implementation Details:**  
Properties allow a class to hide how data is stored or computed. External code interacts with the property as if it were a field, but the class can include logic in the getter or setter without exposing it.
```cs
public class Circle
{
    private double radius;

    public double Radius
    {
        get => radius;
        set => radius = value >= 0 ? value : throw new ArgumentException("Radius cannot be negative.");
    }

    public double Area
    {
        get => Math.PI * radius * radius; // Computed property, no backing field
    }
}
```
The `Area` property is read-only and computed on demand, hiding the calculation logic while encapsulating the `radius` field.

**3. Flexible Access Control:**  
Properties allow fine-grained control over read and write operations. You can make a property read-only (`get` only), write-only (`set` only), or restrict one of them to private/protected access.
```cs
public class BankAccount
{
    private double balance;

    public double Balance
    {
        get => balance; // Public read access
        private set => balance = value >= 0 ? value : throw new ArgumentException("Balance cannot be negative.");
    }

    public void Deposit(double amount)
    {
        if (amount > 0)
            Balance = balance + amount; // Uses private setter
    }
}
```
The `Balance` property allows public reading but restricts modifications to within the class, ensuring controlled updates via methods like `Deposit`.  

**4. Encapsulation Without Changing Interface:**  
Properties allow you to change the internal implementation (e.g., how data is stored or computed) without altering the public interface. External code continues to access the property as if it were a field.
```cs
public class Employee
{
    private string firstName;
    private string lastName;

    public string FullName
    {
        get => $"{firstName} {lastName}"; // Combines two fields
        set
        {
            var parts = value.Split(' ');
            if (parts.Length >= 2)
            {
                firstName = parts[0];
                lastName = parts[1];
            }
            else
            {
                throw new ArgumentException("Full name must include first and last names.");
            }
        }
    }
}
```
External code uses `FullName` as a single property, unaware of the two underlying fields (`firstName`, `lastName`). If the storage changes (e.g., to a single field), the property’s interface remains unchanged.  

**5. Auto-Implemented Properties for Simplicity:**  
For simple cases where no additional logic is needed, C# provides **auto-implemented properties**, which automatically create a private backing field. This simplifies code while maintaining encapsulation.
```cs
public class Product
{
    public string Name { get; set; } // Auto-implemented property
    public decimal Price { get; private set; } // Read-only externally

    public void UpdatePrice(decimal newPrice)
    {
        if (newPrice >= 0)
            Price = newPrice;
    }
}
```
The `Price` property is read-only outside the class, and updates are controlled via `UpdatePrice`, ensuring encapsulation.

**6. Support for Immutability:**  
Using `init`-only properties (introduced in C# 9.0), you can create immutable objects where properties can only be set during object initialization, further enhancing encapsulation by preventing unintended changes.
```cs
public class Order
{
    public int OrderId { get; init; } // Can only be set during initialization
    public DateTime OrderDate { get; init; }
}
```

---

#### Q. What’s the difference between a field and a property in terms of encapsulation? ####  
A **field** is a variable directly declared within a class or struct, typically used to store the internal state of an object.  
A **property** is a class member that provides a controlled interface to access or modify a field (or computed data) through getter and setter methods.  

| Aspect                  | Field                                  | Property                              |
|-------------------------|----------------------------------------|---------------------------------------|
| **Access Control**      | Direct access unless private; no fine-grained control. | Controlled access via `get`/`set`, can be read-only, write-only, or restricted (e.g., `private set`). |
| **Data Hiding**         | Private fields hide data, but public fields expose it completely. | Properties hide the backing field and expose only the intended interface. |
| **Validation/Logic**    | No built-in way to validate or add logic when accessing/modifying. | Getters/setters can include validation, computation, or side effects. |
| **Interface Stability** | Changing a public field to a property breaks the public interface (binary compatibility issue). | Properties maintain a stable interface, allowing internal changes without affecting external code. |
| **Encapsulation Level** | Basic encapsulation with private fields; none with public fields. | Strong encapsulation, even with public properties, due to controlled access and logic. |

---

#### Q. What access modifier would you use for a variable that should only be modified inside the class? ####  
Use the `private` access modifier for a variable that should only be modified inside the class, and optionally expose controlled access via methods or a **property with a private setter**.

---

#### Q. When would you make a property read-only or write-only? ####  
**Read-Only Properties:** Use when you want to allow reading but prevent modification, ensuring immutability, computed values, or controlled state exposure. Implemented with `get` only, `private set`, or `init`.  
**Write-Only Properties:** Use for sensitive data (e.g., passwords, security tokens) or action-triggering scenarios (e.g., logging, updating internal state) where reading is unnecessary or restricted. Implemented with `set` only.

---

#### Q. How do auto-implemented properties relate to encapsulation? ####  
Auto-implemented properties allow you to define a property with a `get` and/or `set` accessor without manually declaring a private backing field. The compiler creates an anonymous private field behind the scenes.  
Syntax: 
```cs
public class Person {
    public string Name { get; set; } // Auto-implemented property
}
```
In this example, the compiler generates a private field (e.g., `<>_name`) and implements the `get` and `set` accessors to interact with it.  

Auto-implemented properties enhance encapsulation in C# by:
- Hiding the compiler-generated private backing field, preventing direct access.
- Allowing controlled access through `get`, `set`, `private set`, or `init` modifiers.
- Maintaining a stable public interface that can be refactored to include logic later.
- Simplifying code while preserving encapsulation principles.  

However, they are best suited for simple scenarios without validation or computed values. For complex logic, manual properties are needed, but auto-implemented properties still provide a strong foundation for encapsulation by ensuring data is accessed through a controlled interface rather than directly via fields.

---

#### Q. How would you refactor a class that exposes all its fields as public? ####
To refactor a class with public fields in C# for encapsulation:  
1. Change public fields to `private`.
2. Replace fields with properties (auto-implemented or manual with validation).
3. Add methods for controlled modifications (e.g., `Deposit` for `Balance`).
4. Use `init` or `private set` for immutability or restricted access.
5. Keep property names same as fields for compatibility.

---

#### Q. How can encapsulation help in a team environment when multiple developers are working on the same codebase? ####
Encapsulation enhances collaboration in a team environment with multiple developers by promoting **modularity**, **data protection**, and **clear interfaces**, which reduce errors, simplify maintenance, and improve code reliability.  
Here’s a concise explanation of how encapsulation helps:  
1. Prevents Unintended Modifications:  
A `BankAccount` class with a private `balance` field and public `Deposit`/`Withdraw` methods ensures teammates can’t set `balance` to invalid values.
2. Reduces Conflicts:  
Changing how `balance` is calculated in a `BankAccount` class doesn’t affect code using its public `Balance` property.
3. Improves Maintainability:  
Validation in a property setter (e.g., `private set` for `Balance`) ensures consistent behavior across the team’s code.
4. Facilitates Division of Work:  
One developer can work on a `Customer` class while another works on a `BankAccount` class, relying on each other’s public methods without interference.
5. Enhances Code Reusability:  
A `Logger` class with a write-only `Message` property can be reused by multiple developers without exposing its logging mechanism.

---

#### Q. Can encapsulation help prevent breaking changes in APIs? How? ####  
- **Library Development**: In a library, encapsulation ensures clients depend only on public properties/methods, allowing internal refactoring without forcing clients to update.
- **Team Collaboration**: Multiple developers can work on the API’s internals without affecting its public contract, reducing coordination overhead.
- **Long-Term Maintenance**: Encapsulation makes it easier to evolve the API (e.g., adding features, optimizing performance) while maintaining backward compatibility.

---

#### Q. What are the drawbacks of too much encapsulation? ####
1. Reduced Flexibility:  
Overly restrictive access (e.g., making everything `private` with no public interface) can hinder legitimate use cases, forcing developers to write workarounds or duplicate code to access needed data.  
**Example**: If a `Balance` property is private with no getter, other classes may need to implement redundant logic to estimate the balance, reducing code reuse.

2. Performance Overhead:  
Wrapping every field access in properties or methods with validation or logic can introduce slight performance costs, especially in performance-critical applications where simple field access would be faster.  

3. Boilerplate Code:  
Over-encapsulation can lead to excessive boilerplate (e.g., getters/setters for every field), increasing code volume and maintenance effort without adding meaningful value.  
**Example**: Auto-implemented properties (`public string Name { get; set; }`) are often sufficient, but over-encapsulation might lead to manual properties with redundant validation for every field.

4. Testing Challenges:  
Excessive encapsulation can make unit testing harder, as private fields and methods are inaccessible. Developers may need to use reflection or expose internal state unnecessarily to test the class.  
**Example**: A private field with no getter requires complex test setups to verify the internal state, increasing test complexity.

---

## Abstraction
Abstraction is a principle that focuses on hiding the complex implementation details of a class while exposing only the essential features or behaviors to the outside world. It allows developers to work with simplified models of objects, focusing on *what* an object does rather than *how* it does it.

### 🎯 Goals of Abstraction
- **Hide Implementation Details**:
  - Users of a class don’t need to know how methods or properties work internally.
  - They only interact with a **clear, defined interface**.
  - *Example*: You can use a `List<T>` without knowing how it resizes internally.
- **Reduce Complexity**:
  - By focusing only on **what** an object does, not **how**, the system becomes easier to understand and manage.
  - *Like a remote control*: You press a button — you don’t worry about how the signal is processed.
- **Improve Code Maintainability**:
  - Changes to internal logic can be made **without affecting** the classes or code that use it — as long as the interface contract remains the same.
- **Enhance Code Reusability**:
  - Abstract structures (like abstract classes or interfaces) can be reused across multiple implementations.
  - *Example*: Interface `ILogger` can be implemented by `FileLogger`, `ConsoleLogger`, etc.
- **Enable Loose Coupling**:
  - Abstraction decouples high-level logic from low-level implementation.
  - Makes code **more modular** and easier to replace or extend.
  - *Example*: Switching from one database to another by abstracting the data access layer.
- **Support Polymorphism**:
  - Abstraction (through interfaces or base classes) enables objects to be used interchangeably via a common type.
  - *Example*: A method that accepts a `Shape` can work with `Circle`, `Square`, etc., without knowing their specific types.

### ✅ Ways C# supports abstraction:

#### 1. Abstract Classes 
- Define a base class with common functionality, leaving some members unimplemented for derived classes.
- Cannot be instantiated directly.
```cs
public abstract class Animal
{
    public abstract void MakeSound(); // Abstract method
    public void Breathe() => Console.WriteLine("Breathing...");
}

public class Dog : Animal
{
    public override void MakeSound() => Console.WriteLine("Bark!");
}

```

#### 2. Interfaces
- Define a contract that implementing classes must follow.
- No implementation (prior to C# 8.0); just signatures.
```cs
public interface IVehicle
{
    void Drive();
}

public class Car : IVehicle
{
    public void Drive() => Console.WriteLine("Driving car...");
}
```

#### 3. Access Modifiers (Encapsulation aiding Abstraction)
- Hide internal class members and expose only what's needed.
- `public`, `private`, `protected`, `internal`, `protected internal`, `private protected`
```cs
public class BankAccount
{
    private decimal balance; // Hidden implementation
    public void Deposit(decimal amount) => balance += amount; // Public API
}
```

#### 4. Delegates and Events
Delegates and events allow you to abstract method invocation so that caller doesn't know who handles the operation.
```cs
public delegate void Notify();  // Delegate declaration

class Process
{
    public event Notify ProcessCompleted;  // Event using delegate

    public void Start()
    {
        Console.WriteLine("Process started...");
        // Some logic
        ProcessCompleted?.Invoke();  // Raise event
    }
}

class Program
{
    static void Main()
    {
        Process p = new Process();
        p.ProcessCompleted += () => Console.WriteLine("Process completed.");
        p.Start();
    }
}
```

#### 5. Virtual Methods and Method Overriding
- Virtual methods allow derived classes to override base class implementations, enabling abstraction by letting subclasses redefine behavior while adhering to a common interface.
- **Use Case**: To provide a default implementation that can be customized by derived classes.
```cs
class Vehicle
{
    public virtual void Start()
    {
        Console.WriteLine("Vehicle starting...");
    }
}

class Car : Vehicle
{
    public override void Start()
    {
        Console.WriteLine("Car engine revving!");
    }
}
```

### Interview Questions

#### Q. What is an abstract class? Can it have concrete methods? Can it have constructors?  
An abstract class in C# is a class that cannot be instantiated directly and serves as a blueprint for derived classes. It is designed to define common behavior and structure for a group of related classes, often encapsulating shared functionality while leaving specific implementations to subclasses. Abstract classes are declared using the `abstract` keyword and are used to achieve abstraction in object-oriented programming by focusing on "what" a class does rather than "how" it does it.  

- Key Characteristics:
  - Cannot be instantiated (e.g., `new AbstractClass()` is not allowed).
  - Can contain **abstract members** (methods, properties, etc.) that have no implementation and must be implemented by derived classes.
  - Can contain **concrete members** (methods, properties, fields, etc.) with full implementations.
  - Used as a base class for inheritance.
  
```cs
abstract class Animal
{
    public abstract void MakeSound(); // Abstract method (no implementation)
}

class Dog : Animal
{
    public override void MakeSound()
    {
        Console.WriteLine("Woof!");
    }
}

// Usage
Dog dog = new Dog();
dog.MakeSound(); // Output: Woof!
// Animal animal = new Animal(); // Error: Cannot instantiate abstract class
```

An abstract class can have **concrete methods** (methods with full implementation). These methods provide shared functionality that derived classes can use as-is or override (if marked as `virtual`). This allows abstract classes to define common behavior while still enforcing abstraction for specific methods.
```cs
abstract class Vehicle
{
    public abstract void StartEngine(); // Abstract method
    public void Stop() // Concrete method
    {
        Console.WriteLine("Vehicle stopped.");
    }
}

class Car : Vehicle
{
    public override void StartEngine()
    {
        Console.WriteLine("Car engine started.");
    }
}

// Usage
Car car = new Car();
car.StartEngine(); // Output: Car engine started.
car.Stop();        // Output: Vehicle stopped.
```

An abstract class can have **constructors**, which are used to initialize fields or properties when a derived class is instantiated. Since an abstract class cannot be instantiated directly, its constructor is called by the derived class' constructor (explicitly or implicitly). Constructors in abstract classes are typically used to enforce initialization logic for shared fields.
```cs
abstract class Shape
{
    protected string color;
    public Shape(string color) // Constructor
    {
        this.color = color;
    }
    public abstract double CalculateArea();
    public void DisplayColor()
    {
        Console.WriteLine($"Color: {color}");
    }
}

class Rectangle : Shape
{
    private double width, height;
    public Rectangle(string color, double width, double height) : base(color)
    {
        this.width = width;
        this.height = height;
    }
    public override double CalculateArea()
    {
        return width * height;
    }
}

// Usage
Rectangle rect = new Rectangle("Blue", 5, 3);
rect.DisplayColor(); // Output: Color: Blue
Console.WriteLine(rect.CalculateArea()); // Output: 15
```
The abstract class `Shape` has a constructor that initializes the `color` field. The `Rectangle` class calls this constructor using `base(color)` to ensure the `color` field is set when a `Rectangle` object is created.

---

#### Q. What is an interface? Can a class implement multiple interfaces?  
An interface in C# is a contract that defines a set of methods, properties, events, or indexers that a class or struct must implement, without providing any implementation details. It focuses on "what" must be done, not "how" it is done, promoting abstraction and loose coupling in object-oriented programming. Interfaces are declared using the `interface` keyword and are typically used to ensure that different classes adhere to a common set of behaviors.

- Key Characteristics:
  - Contains only member declarations (no implementation until C# 8.0 introduced default implementations, which are rarely used).
  - Cannot be instantiated directly.
  - Classes or structs that implement an interface must provide implementations for all its members.
  - Supports polymorphism by allowing objects to be treated as the interface type.
```cs
interface IAnimal
{
    void MakeSound(); // Method signature
    string Name { get; set; } // Property signature
}

class Dog : IAnimal
{
    public string Name { get; set; }
    public void MakeSound()
    {
        Console.WriteLine("Woof!");
    }
}

// Usage
IAnimal dog = new Dog { Name = "Buddy" };
dog.MakeSound(); // Output: Woof!
Console.WriteLine(dog.Name); // Output: Buddy
```

A class in C# can implement **multiple interfaces**. This is a key feature that allows a class to conform to multiple contracts, enabling flexible design and supporting multiple behaviors. Unlike inheritance, where a class can only inherit from one base class, a class can implement any number of interfaces by separating them with commas in the class declaration.
- Key Points:
  - Each interface’s members must be implemented by the class.
  - Multiple interface implementation is useful for combining unrelated behaviors (e.g., a class can be both `IDisposable` and `IComparable`).
  - If interfaces have conflicting member names, explicit interface implementation can be used to resolve ambiguity.
```cs
interface IPrinter
{
    void Print();
}

interface IScanner
{
    void Print();
}

class MultiFunctionDevice : IPrinter, IScanner
{
    void IPrinter.Print()
    {
        Console.WriteLine("Printing document...");
    }

    void IScanner.Print()
    {
        Console.WriteLine("Printing scanned image...");
    }
}

// Usage
MultiFunctionDevice device = new MultiFunctionDevice();
((IPrinter)device).Print(); // Output: Printing document...
((IScanner)device).Print(); // Output: Printing scanned image...
```

---

#### Q. When would you use an abstract class instead of an interface?
An abstract class is used instead of an interface when you want to provide a common base with shared implementation, state, or behavior that derived classes can inherit. Here are some scenarios where an abstract class is preferred over an interface:  

**1. Shared Implementation**:  
Abstract classes can contain concrete methods, fields, and properties with shared implementation, which derived classes can use or override.  
Interfaces (prior to C# 8.0) only define contracts without implementation, and even with default implementations in C# 8.0+, they are less suited for sharing complex logic.
```cs
abstract class Vehicle
{
    protected int speed; // Shared state
    public void Stop() // Shared concrete method
    {
        speed = 0;
        Console.WriteLine("Vehicle stopped.");
    }
    public abstract void Drive(); // Abstract method for specific behavior
}

class Car : Vehicle
{
    public override void Drive()
    {
        speed = 60;
        Console.WriteLine($"Car driving at {speed} km/h.");
    }
}

// Usage
Car car = new Car();
car.Drive(); // Output: Car driving at 60 km/h.
car.Stop();  // Output: Vehicle stopped.
```
The `Stop` method and `speed` field are shared across all `Vehicle` types, avoiding code duplication. An interface would require each class to implement `Stop` independently.

**2. State Management**:
Abstract classes can maintain state through fields (e.g., private or protected variables), properties, or methods, allowing derived classes to inherit and manipulate shared data.
Interfaces cannot hold state; they only define behavior.
```cs
abstract class Shape
{
    protected string color; // Field to store state
    public Shape(string color)
    {
        this.color = color;
    }
    public abstract double CalculateArea();
    public string GetColor() => color; // Shared method
}

class Circle : Shape
{
    private double radius;
    public Circle(string color, double radius) : base(color)
    {
        this.radius = radius;
    }
    public override double CalculateArea()
    {
        return Math.PI * radius * radius;
    }
}

// Usage
Circle circle = new Circle("Red", 5);
Console.WriteLine(circle.GetColor()); // Output: Red
Console.WriteLine(circle.CalculateArea()); // Output: 78.54
```
The `color` field and `GetColor` method are shared, and the constructor enforces initialization. An interface cannot store fields or enforce such initialization.

**3. Access Modifiers**:
Abstract classes can use access modifiers (`private`, `protected`, `internal`, etc.) to control visibility of members, allowing finer control over encapsulation. Interfaces typically have public members (implicitly or explicitly).
```cs
abstract class Appliance
{
    protected bool isOn; // Protected field
    protected void Reset() // Protected method
    {
        isOn = false;
        Console.WriteLine("Appliance reset.");
    }
    public abstract void Operate();
}

class Fan : Appliance
{
    public override void Operate()
    {
        isOn = true;
        Console.WriteLine("Fan is spinning.");
    }
    public void Stop()
    {
        Reset(); // Access protected method
        Console.WriteLine("Fan stopped.");
    }
}

// Usage
Fan fan = new Fan();
fan.Operate(); // Output: Fan is spinning.
fan.Stop();    // Output: Appliance reset. Fan stopped.
```
The `Reset` method is `protected`, accessible only to derived classes, ensuring controlled access. Interfaces cannot have protected members. 

> However, with C# 8.0 and later, default interface implementations allow for `private`, `protected`, `internal`, `public`, `virtual`, `abstract`, `sealed`, `static`, `extern`, and `partial` modifiers on members under specific conditions.  
> For example, a private method with a default implementation can be added to an interface.

---

#### Q. Can an abstract class implement an interface?
- Yes, An abstract class can implement some or all of the interface's members (methods, properties, etc.).
- If the abstract class does not implement all interface members, it must declare the unimplemented members as `abstract`, and derived classes must provide the implementations.
- This approach combines the benefits of interfaces (defining contracts) with abstract classes (shared state and implementation).

**1. Abstract Class Fully Implements the Interface**  
The abstract class provides concrete implementations for all interface members, and derived classes inherit these implementations.
```cs
interface IDrawable
{
    void Draw();
}

abstract class Shape : IDrawable
{
    protected string color;
    public Shape(string color)
    {
        this.color = color;
    }
    public void Draw() // Concrete implementation of interface method
    {
        Console.WriteLine($"Drawing a {color} shape.");
    }
}

class Circle : Shape
{
    public Circle(string color) : base(color) { }
}

// Usage
Circle circle = new Circle("Red");
circle.Draw(); // Output: Drawing a Red shape.
```
**Explanation**: The `Shape` abstract class implements the `IDrawable` interface by providing a concrete `Draw` method. The `Circle` class inherits this implementation without needing to override it.  

**2. Abstract Class Partially Implements the Interface**  
The abstract class implements some interface members and leaves others as abstract, requiring derived classes to implement them.
```cs
interface IVehicle
{
    void Start();
    void Stop();
}

abstract class Vehicle : IVehicle
{
    protected string model;
    public Vehicle(string model)
    {
        this.model = model;
    }
    public void Stop() // Concrete implementation
    {
        Console.WriteLine($"{model} stopped.");
    }
    public abstract void Start(); // Abstract method for interface member
}

class Car : Vehicle
{
    public Car(string model) : base(model) { }
    public override void Start() // Must implement the abstract method
    {
        Console.WriteLine($"{model} engine started.");
    }
}

// Usage
Car car = new Car("Toyota");
car.Start(); // Output: Toyota engine started.
car.Stop();  // Output: Toyota stopped.
```
**Explanation**: The `Vehicle` abstract class implements the `IVehicle` interface, providing a concrete `Stop` method but leaving `Start` as abstract. The `Car` class must implement `Start`.  

**3. Abstract Class Implements Multiple Interfaces**  
An abstract class can implement multiple interfaces, either fully or partially, just like any other class.
```cs
interface IMovable
{
    void Move();
}

interface IDescribable
{
    string GetDescription();
}

abstract class Animal : IMovable, IDescribable
{
    protected string name;
    public Animal(string name)
    {
        this.name = name;
    }
    public void Move() // Concrete implementation
    {
        Console.WriteLine($"{name} is moving.");
    }
    public abstract string GetDescription(); // Abstract method
}

class Dog : Animal
{
    public Dog(string name) : base(name) { }
    public override string GetDescription()
    {
        return $"A dog named {name}.";
    }
}

// Usage
Dog dog = new Dog("Buddy");
dog.Move(); // Output: Buddy is moving.
Console.WriteLine(dog.GetDescription()); // Output: A dog named Buddy.
```
**Explanation**: The `Animal` abstract class implements both `IMovable` and `IDescribable` interfaces, providing a concrete `Move` method and leaving `GetDescription` as abstract for derived classes like `Dog` to implement.

---
#### Q. What are default interface methods in C# 8.0+?
Default interface methods are methods with implementation defined directly within an interface. Before C# 8.0, interfaces could only contain method declarations, but now they can include both the declaration and the method body. These methods are also known as **virtual extension methods**.
```cs
public interface ILogger 
{
    void Log(string info); // Abstract method (traditional)
    
    // Default interface method with implementation
    public void LogInfo(string typeofInformation, string info) 
    {
        Console.Write(typeofInformation + " " + info);
    }
}
```
- Default interface methods are virtual by default, allowing them to be overridden in derived interfaces
- They support various access modifiers: private, protected, internal, public, virtual, abstract, override, sealed, static, and extern
- The explicit access modifier for default methods is public if no modifier is specified  

**Inheritance Behavior:**  
A crucial aspect of default interface methods is that **implementing classes don't automatically inherit them**. The class doesn't know about the existence of default methods and doesn't contain their implementation. To access default methods, you must cast the object to the interface type
```cs
public class TextLogger : ILogger 
{
    public void Log(string info) => Console.Write("In base Logger");
}

// Usage
TextLogger logger = new TextLogger();
// logger.LogInfo(...); // This won't work

ILogger interfaceLogger = logger;
interfaceLogger.LogInfo("Test", "message"); // This works
```
**API Evolution Without Breaking Changes:**  
The main advantage is backward compatibility. API authors can add new methods to existing interfaces without breaking existing implementations. This solves a long-standing problem where adding methods to interfaces would force all implementing classes to be updated.

---

#### Q. What is the use of protected members in C# interfaces?
In C# 8.0 and later, interfaces can have protected members.  
However, unlike classes, where protected allows access within the same class and derived classes, the purpose and usage of protected members in interfaces are a bit different.  
- **Access is limited to derived interfaces, not derived classes**: A `protected` member in an interface can only be accessed by interfaces that inherit from it. Classes that implement the interface cannot directly access these `protected` members.
- **Explicit implementation required**: When a class implements an interface with `protected` members, it needs to explicitly implement those members, meaning the implementation must be qualified with the interface name.  
  
**Potential Use Cases**  
While less common than in classes, `protected` interface members can be useful in **scenarios involving interface hierarchies** where you want to provide helper methods or properties that are only relevant to the internal implementation details of derived interfaces.  
For example, consider a situation where you have a base interface `IInventoryController` with a `protected` method `PullInventoryItem()`. Derived interfaces could then utilize this protected method for their internal logic, without exposing it to classes that simply implement the interface.  

> The primary purpose of interfaces remains defining contracts and abstracting behavior. Overusing default implementations and `protected` members might make interfaces behave more like abstract classes, potentially blurring the lines between these two concepts.

---

#### Q. How is abstraction achieved in functional programming in C#?  
Abstraction in functional programming in C# is about hiding the complex implementation details and exposing only the necessary functionalities to the user. While C# is traditionally an object-oriented language, it has strong support for functional programming paradigms where abstraction is primarily achieved through **higher-order functions**, **delegates**, and **LINQ abstractions**.  

**1. Higher-Order Functions**   
Higher-order functions are functions that take other functions as arguments or return them as results. This allows you to abstract over behaviors, not just data.  
Example: Using `Func<T, TResult>` to Abstract Behavior
```cs
// Higher-order function that performs an operation on two integers
int Compute(int a, int b, Func<int, int, int> operation)
{
    return operation(a, b);
}

// Usage:
int sum = Compute(3, 4, (x, y) => x + y);        // sum = 7
int product = Compute(3, 4, (x, y) => x * y);    // product = 12
```
Here, the implementation details of addition or multiplication are abstracted away, and you can pass any operation you need at the call site.

**2. Delegates and Lambdas**  
Delegates and lambda expressions let you treat functions as first-class objects, further enabling abstraction by decoupling what is done from how it is done.
```cs
// Define a delegate
public delegate bool Criteria(int value);

// Abstracted filter function
IEnumerable<int> Filter(IEnumerable<int> numbers, Criteria criteria)
{
    foreach (var n in numbers)
    {
        if (criteria(n)) yield return n;
    }
}

// Usage:
var oddNumbers = Filter(new[] {1, 2, 3, 4, 5}, x => x % 2 != 0);
```

**3. LINQ as Functional Abstraction**  
LINQ provides a high-level and expressive way to abstract data transformation pipelines.
```cs
var squares = numbers.Select(n => n * n);  // abstracts away explicit iteration
```

**4. Using Interfaces and Abstract Classes**  
While more common in OOP, interfaces and abstract classes can also serve as abstractions in functional style, especially when you expose only behaviors without implementation details.
```cs
public interface IOperation
{
    int Apply(int x, int y);
}

public class Addition : IOperation
{
    public int Apply(int x, int y) => x + y;
}

public class Multiplication : IOperation
{
    public int Apply(int x, int y) => x * y;
}

// Usage:
IOperation op = new Addition();
int result = op.Apply(2, 3); // result = 5
```
This allows you to pass operations around abstractly, without needing to know their concrete implementation.

---

## Inheritance
Inheritance is the mechanism that allows one class (called the **child** or **derived class**) to acquire the properties (fields) and behaviors (methods) of another class (called the **parent** or **base class**), enabling code reuse and establishing a hierarchical relationship between classes. Inheritance is a fundamental concept in object-oriented programming (OOP) that promotes the **"is-a"** relationship between classes, allowing derived classes to extend or modify the functionality of base classes. 
> If class `Car` inherits from class `Vehicle`, we can say: "A Car is a Vehicle."

### 🎯 Goals of Inheritance
- **Code Reusability**: 
  - Allows derived classes to reuse code from base classes, reducing duplication and improving maintainability.
  - **Example**: `Vehicle` defines `Start()` and `Stop()`.  
  `Car`, `Truck`, `Bike` all inherit and reuse these methods without rewriting.

- **Extensibility**:
    - Add **new functionality** to a derived class without changing the base class.
    - Supports **open/closed principle** (Open for extension, closed for modification).
    - **Example**: You can add `TurboBoost()` to `SportsCar` without altering the base class `Vehicle`.
  
- **Maintainability**:
    - If shared behavior changes, update it **once** in the base class and it reflects in all derived classes.
    - Reduces maintenance effort and chance of inconsistency.

- **Polymorphism**:
    - Treat different derived classes as instances of the same base type, enabling **dynamic method dispatch**.
    - **Example**: Even though the list is of type `Vehicle`, it works for all subclasses.
    ```cs
    List<Vehicle> vehicles = new List<Vehicle> { new Car(), new Truck() };
    foreach (var v in vehicles) v.Start();
    ```
- **Logical Hierarchy & Clarity**:
    - Organizes code into **natural “is-a” relationships**.
    - Improves readability and helps model real-world entities in a structured way.
    - **Example**:
    ```
    Animal
        ↳ Mammal
            ↳ Dog
            ↳ Cat
        ↳ Bird
            ↳ Sparrow
    ```


### ✅ Ways C# supports inheritance:

#### 1. Class Inheritance
C# supports single inheritance for classes, where a derived class can inherit from one base class using the `:` syntax:
```cs
public class Animal { }
public class Dog : Animal { }
```

#### 2. Interface Implementation
Classes can implement multiple interfaces, providing a form of multiple inheritance for contracts:
```cs
public class Animal { }
public interface IMovable { }
public interface ISpeakable { }
public class Dog : Animal, IMovable, ISpeakable { }
```

#### 3. Virtual and Override Keywords
Base classes can define virtual methods that derived classes can override:
```cs
public class Animal
{
    public virtual void MakeSound() { }
}
public class Dog : Animal
{
    public override void MakeSound() { Console.WriteLine("Bark"); }
}
```

#### 4. Abstract Classes and Methods
Abstract classes cannot be instantiated directly and can contain abstract methods that must be implemented by derived classes:
```cs
public abstract class Shape
{
    public abstract double CalculateArea();
}

public class Circle : Shape
{
    private double radius;
    public Circle(double radius) { this.radius = radius; }
    public override double CalculateArea() => Math.PI * radius * radius;
}
```

#### 5. Access Modifiers
C# provides `protected` access modifier specifically for inheritance, allowing members to be accessible to derived classes but not to external code.

#### 6.Base Keyword
The `base` keyword allows derived classes to access members of the base class, including constructors, methods, and properties:
```cs
public class Dog : Animal
{
    public override void MakeSound()
    {
        base.MakeSound(); // Call base implementation
        Console.WriteLine("Bark");
    }
}
```

#### 7. Sealed Classes and Methods
C# allows you to prevent further inheritance by marking a class as `sealed` or a method as `sealed` in a derived class:
```cs
public sealed class FinalClass
{
    public void Display() { Console.WriteLine("Final Class"); }
}

public class BaseClass
{
    public virtual void Display() { Console.WriteLine("Base Class"); }
}

public class DerivedClass : BaseClass
{
    public sealed override void Display() { Console.WriteLine("Derived Class"); }
    // note: only override methods can be marked as sealed
}
```

### Interview Questions

#### Q. What is the syntax for inheritance in C#?
In C#, inheritance is implemented using the `:` syntax. A derived class inherits from a base class by specifying the base class name after the colon. Here’s the basic syntax:

```cs
public class BaseClass { }
public class DerivedClass : BaseClass { }
```

**Key points about C# inheritance:**
- **Single inheritance**: A class can only inherit from one base class directly
- Multiple inheritance can be achieved using interfaces.
- **Access modifiers**: Derived classes inherit all `public`, `protected`, and `internal` members from the base class, but not `private` members
- **Constructor chaining**: Use `base()` to call base class constructors
- **Method overriding**: Use `virtual` in base class and `override` in derived class

---

#### Q. Can a class inherit from multiple classes in C#? Why or why not?
No, a class cannot inherit from multiple classes in C#. C# supports **single inheritance** for classes, meaning a derived class can only have one direct base class. This design choice avoids the complexities and ambiguities associated with multiple inheritance, such as the **diamond problem**, where a derived class inherits from two classes that both inherit from a common base class.
Instead, C# provides a way to achieve similar functionality through the use of **interfaces**. A class can implement multiple interfaces, allowing it to inherit and fulfill multiple contracts while maintaining clear and unambiguous class hierarchies.  
- **Multiple Interface Implementation:**: A class can implement multiple interfaces
    ```cs
    public class MyClass : BaseClass, IInterface1, IInterface2, IInterface3  // ✓ Valid
    {
        // Must implement all interface members
    }
    ```
- **Interface Inheritance Chain:**: Interfaces themselves can inherit from multiple interfaces
    ```cs
    public interface IInterface1 { }
    public interface IInterface2 { }
    public interface ICombinedInterface : IInterface1, IInterface2 { }  // ✓ Valid
    ```

---

#### Q. What is the difference between public, protected, and private inheritance in C#?
In C#, the terms **public inheritance**, **protected inheritance**, and **private inheritance** as they appear in some other languages like C++ do not exist as distinct forms of inheritance. Instead, C# uses access modifiers **public**, **protected**, and **private** primarily to control member accessibility, not inheritance itself. Here's how these modifiers relate to inheritance and member access in C#:

- **public**: Members declared `public` are accessible from any other code in any assembly. When a base class member is public, it is accessible through the derived class instance anywhere.
- **protected**: Members declared `protected` are accessible within the declaring class and by derived classes. This is the key modifier that enables a derived class to access base class members that are not public but still intended for subclasses.
- **private**: Members declared `private` are accessible only within the declaring class itself, and they are not accessible in derived classes. Such members are not inherited in an accessible form.  

**Access Modifier Summary**:
| Modifier | Accessible From |
| --- | --- |
| `public` | Everywhere |
| `protected` | Same class + derived classes |
| `internal` | Same assembly |
| `protected internal` | Same assembly OR derived classes |
| `private protected` | Same assembly AND derived classes |
| `private` | Same class only |

**Example**:
```cs
public class BaseClass
{
    public int PublicField;        // Accessible everywhere
    protected int ProtectedField;  // Accessible in derived classes
    private int PrivateField;      // Only accessible within this class
    internal int InternalField;    // Accessible within same assembly
}

public class DerivedClass : BaseClass
{
    public void TestAccess()
    {
        PublicField = 1;      // ✓ Accessible
        ProtectedField = 2;   // ✓ Accessible (inherited)
        InternalField = 3;    // ✓ Accessible (same assembly)
        // PrivateField = 4;  // ✗ Not accessible
    }
}
```

---

#### Q. What is the difference between inheritance and composition?
**Inheritance ("is-a" relationship)**  
Inheritance creates a parent-child relationship where the derived class extends or specializes the base class.
- Represents an "is-a" relationship (a Car is a Vehicle)
- Derived class inherits all public and protected members from the base class
- Supports polymorphism - you can treat derived objects as base class objects
- Creates a tight coupling between classes
- Established at compile time and cannot be changed at runtime
```csharp
public class Vehicle
{
    public void Start() { /* implementation */ }
    public void Stop() { /* implementation */ }
}

public class Car : Vehicle  // Car IS-A Vehicle
{
    public void OpenTrunk() { /* implementation */ }
}
```

**Composition ("has-a" relationship)**  
Composition involves building classes by including instances of other classes as members.
- Represents a "has-a" relationship (a Car has an Engine)
- The containing class uses functionality from contained objects
- Creates loose coupling between classes
- More flexible - can change behavior at runtime by swapping composed objects
- Follows the principle "favor composition over inheritance"
```csharp
public class Engine
{
    public void Start() { /* implementation */ }
    public void Stop() { /* implementation */ }
}

public class Car
{
    private Engine engine;  // Car HAS-AN Engine
    
    public Car()
    {
        engine = new Engine();
    }
    
    public void Start()
    {
        engine.Start();  // Delegates to composed object
    }
}
```

**Use Inheritance when:**  
- There's a clear "is-a" relationship
- You need polymorphism
- The relationship is stable and unlikely to change
- You want to share common interface/behavior across related classes

**Use Composition when:**
- There's a "has-a" relationship
- You need flexibility to change behavior at runtime
- You want to avoid deep inheritance hierarchies
- You need to combine functionality from multiple sources
- You want looser coupling between components

---

#### Q. What is the difference between `virtual`, `override`, and `new` keywords?
The `virtual`, ` override`, and `new` keywords in C# are used to control polymorphism and the way methods, properties, or indexers behave in class hierarchies. Here's how they differ:
| Keyword  | Used In      | Purpose                                                        | Behavior                                                                 |
|----------|--------------|----------------------------------------------------------------|--------------------------------------------------------------------------|
| virtual  | Base class   | Declares that a method/property/indexer can be overridden in a derived class | Enables a derived class to provide its own implementation using override. |
| override | Derived class| Indicates that a method/property/indexer overrides a virtual/abstract member in base | Provides a new implementation that replaces the base class’s virtual/abstract implementation. |
| new      | Derived class| Hides a member of the base class (not override)               | Defines a new member with the same name, hiding the base member—this is not overriding and is not polymorphic. |

**`virtual`:**
- Declared in the base class to let derived classes override the method/property/indexer.
- Invoking a virtual member on a base reference will call the most derived override at runtime.
- Example:
    ```csharp
    public class BaseClass {
        public virtual void Display() {
            Console.WriteLine("BaseClass Display");
        }
    }
    ```

**`override`:**
- Used in the derived class to provide a new implementation for a virtual or abstract member from the base class.
- Method signature must match the base class's virtual method.
- Example:
    ```csharp
    public class DerivedClass : BaseClass {
        public override void Display() {
            Console.WriteLine("DerivedClass Display");
        }
    }
    ```

**`new`:**
- Used when you want to hide a member inherited from the base class, *not* override it.
- The base class version and the derived class version are treated as entirely separate.
- Hide any member (including non-virtual ones), but this does not participate in polymorphism.
- Example:
    ```csharp
    public class DerivedClass : BaseClass {
        public new void Display() {
            Console.WriteLine("DerivedClass Display (New)");
        }
    }
    ```

**Polymorphism Comparison:**
- `override` enables true polymorphism—calling through a base reference uses the derived override.
- `new` only hides the base implementation—calling through a base reference uses the base version; calling through a derived reference uses the new version.
- Example:
    ```csharp
    BaseClass obj = new DerivedClass();
    obj.Display();

    // override: invokes DerivedClass.Display()
    // new: invokes BaseClass.Display()
    ```

---

#### Q. Can constructors be inherited in C#? If not, how are base constructors called?
In C#, constructors are **not inherited** by derived classes. This means that when a class derives from a base class, it does not automatically gain the constructors of the base class. Constructors are not considered class members and, therefore, are not inherited in the same way that methods or properties are. 

**How Base Constructors Are Called**  
When you create a derived class constructor, you can explicitly call a base class constructor using the `base` keyword:
```csharp
public class Animal
{
    public string Name { get; set; }
    public int Age { get; set; }
    
    // Base class constructor
    public Animal(string name, int age)
    {
        Name = name;
        Age = age;
    }
}

public class Dog : Animal
{
    public string Breed { get; set; }
    
    // Derived class constructor calling base constructor
    public Dog(string name, int age, string breed) : base(name, age)
    {
        Breed = breed;
    }
}
```

**Default Constructor Behavior**  
If you don't explicitly call a base constructor, C# automatically calls the parameterless constructor of the base class. This can cause compilation errors if the base class doesn't have a parameterless constructor:
```csharp
public class Animal
{
    public Animal(string name) { } // Only parameterized constructor
}

public class Dog : Animal
{
    // This will cause a compiler error because Animal has no parameterless constructor
    public Dog() 
    {
    }
    
    // This works - explicitly calls the base constructor
    public Dog(string name) : base(name)
    {
    }
}
```

**Constructor Chaining**  
You can also chain constructors within the same class using `this`:
```csharp
public class Dog : Animal
{
    public string Breed { get; set; }
    
    public Dog(string name) : this(name, 0, "Unknown")
    {
    }
    
    public Dog(string name, int age, string breed) : base(name, age)
    {
        Breed = breed;
    }
}
```
The key point is that while constructors aren't inherited, the base class constructor logic still runs when creating derived class instances - you just need to explicitly specify which base constructor to call if there isn't a parameterless one available.

---

#### Q. What is method hiding in C# and how does it differ from overriding?
Method hiding in C# is a mechanism that allows a derived class to define a new method with the same signature as a method in its base class, effectively "hiding" the base class method. This is accomplished using the `new` keyword.  

**Method Hiding (`new` keyword):**  
- Creates a completely new method that shadows the base class method
- The method called depends on the compile-time type of the variable
- No polymorphic behavior - each class has its own independent method
- The base class method is still accessible through casting or base class references

**Method Overriding (`override` keyword):**  
- Replaces the base class method implementation
- Requires the base method to be marked as `virtual`, `abstract`, or `override`
- Exhibits polymorphic behavior - the actual runtime type determines which method is called
- The base class method is completely replaced in the inheritance hierarchy

**Example:**
```csharp
// Base class
public class Animal
{
    public virtual void MakeSound() => Console.WriteLine("Animal makes a sound");
    public virtual void Move() => Console.WriteLine("Animal moves");
}

// Method Overriding
public class Dog : Animal
{
    public override void MakeSound() => Console.WriteLine("Dog barks");
}

// Method Hiding
public class Cat : Animal
{
    public new void Move() => Console.WriteLine("Cat prowls silently");
}

// Usage
Animal animal1 = new Dog();
Animal animal2 = new Cat();

animal1.MakeSound(); // Output: "Dog barks" (polymorphic - override)
animal2.Move();      // Output: "Animal moves" (non-polymorphic - hiding)

Cat cat = new Cat();
cat.Move();          // Output: "Cat prowls silently" (direct call to hidden method)
```

**Key Differences:**  
- **Polymorphism:** Overriding maintains polymorphic behavior, while hiding breaks it
- **Virtual method table:** Overriding updates the vtable entry, hiding creates a separate entry
- **Accessibility:** Hidden methods can still be accessed through base class references
- **Design intent:** Overriding is for "is-a" relationships, hiding is for "replaces functionality"

Method hiding is generally discouraged unless you specifically need to break polymorphic behavior, as it can lead to confusing code where the method called depends on how the object is referenced rather than its actual type.

---

#### Q. What is the purpose of the `base` keyword in inheritance?  
The `base` keyword in inheritance serves to access members (methods, properties, constructors, etc.) from the parent class within a derived class. Its primary purposes are:  

**1. Calling Parent Class Constructors**  
```csharp
public class Animal
{
    public string Name { get; set; }
    
    public Animal(string name)
    {
        Name = name;
    }
}

public class Dog : Animal
{
    public string Breed { get; set; }
    
    public Dog(string name, string breed) : base(name)  // Calls Animal constructor
    {
        Breed = breed;
    }
}
```

**2. Accessing Overridden Methods**  
```csharp
public class Animal
{
    public virtual void MakeSound()
    {
        Console.WriteLine("Some generic animal sound");
    }
}

public class Dog : Animal
{
    public override void MakeSound()
    {
        base.MakeSound();  // Call parent's version first
        Console.WriteLine("Woof!");
    }
}
```

**3. Accessing Hidden Members**
```csharp
public class Parent
{
    public void Display()
    {
        Console.WriteLine("Parent display");
    }
}

public class Child : Parent
{
    public new void Display()
    {
        base.Display();  // Access parent's hidden method
        Console.WriteLine("Child display");
    }
}
```

**Key Benefits:**  
- **Code reuse**: Extend parent functionality rather than completely replacing it
- **Proper initialization**: Ensure parent class constructors are called appropriately
- **Maintainability**: Changes to parent class behavior automatically propagate to derived classes when using `base`
- **Avoiding duplication**: No need to rewrite parent class logic in derived classes  

In summary, the **base keyword** is essential in inheritance for explicitly referencing the base class's implementation, ensuring correct object initialization, and enabling you to build upon or integrate with underlying logic from parent classes.

---

#### Q. What happens if a derived class does not call the base class constructor?
When a **derived class does not explicitly call a base class constructor** in C#, outcomes depend on whether the base class has a parameterless (default) constructor:

- **If the base class has a default constructor:**
  The compiler automatically inserts a call to `base()` at the start of the derived class constructor. The base part of the object gets initialized using the base’s default constructor before any code in the derived constructor runs. This ensures the base class is always properly initialized.

- **If the base class does not have a default constructor:**
  The compiler cannot insert a default call to `base()`. In this situation, if the derived class does not explicitly call a base constructor (with required arguments) using : `base(args)`, a compile-time error occurs. You must use the `base` keyword in the constructor initializer of the derived class to call an available base constructor with appropriate parameters.

> **Constructor Execution Order:**  
> The base class constructor is always executed *before* the derived class constructor body runs, ensuring the base part of the object is set up first.

---

#### Q. What is the difference between interface inheritance and class inheritance in C#?
In C#, interface inheritance and class inheritance are two different mechanisms for establishing relationships between types, each serving distinct purposes:  

**Class Inheritance**  
Class inheritance creates an "is-a" relationship where a derived class inherits implementation from a base class.
- **Single inheritance**: A class can only inherit from one base class
- **Implementation inheritance**: The derived class inherits both the interface (method signatures) and implementation (method bodies) from the base class
- **Access to base members**: Derived classes can access protected and public members of the base class
- **Method overriding**: Virtual methods can be overridden in derived classes
- **Constructor chaining**: Base class constructors are called during derived class instantiation
```csharp
public class Animal {
    public virtual void MakeSound() { Console.WriteLine("Some sound"); }
    protected string name;
}

// Class inheritance 
public class Dog : Animal { 
    public override void MakeSound() { Console.WriteLine("Woof!"); }
}
```

**Interface Inheritance**   
Interface inheritance establishes a contract that implementing classes must fulfill. 
- **Multiple inheritance**: A class can implement multiple interfaces 
- **Contract inheritance**: Interfaces define what methods/properties must exist, but not how they're implemented
- **Polymorphism**: Different classes can implement the same interface in different ways
- **Loose coupling**: Promotes flexible, testable code design
```csharp
public interface IFlyable { void Fly(); }

public interface ISwimmable { void Swim(); }

// Class + interface inheritance
public class Duck : Animal, IFlyable, ISwimmable {
    public void Fly() { Console.WriteLine("Flying with wings"); }
    public void Swim() { Console.WriteLine("Swimming with webbed feet"); }
}
```
> Interface inheritance is particularly valuable for dependency injection, unit testing, and creating flexible architectures where you want to depend on abstractions rather than concrete implementations.

---

#### Q. What are abstract classes, and how do they relate to inheritance?
Abstract classes in C# are classes that cannot be instantiated directly but serve as base classes for other classes. They're designed to provide a common structure and shared functionality that derived classes can inherit and build upon.
- **Cannot be instantiated**: You cannot create objects directly from an abstract class using `new`. They exist solely to be inherited by other classes.
- **Can contain both abstract and concrete members**: Abstract classes can have regular methods with implementations alongside abstract methods that must be implemented by derived classes.
- **Use the `abstract` keyword**: Both the class and any abstract methods within it must be marked with the `abstract` modifier.

Abstract classes are fundamentally tied to inheritance - they establish an "is-a" relationship between the base abstract class and its derived classes. Here's how they work together:
- **Enforced Implementation**: When a class inherits from an abstract class, it must implement all abstract methods. This ensures that derived classes follow a specific contract while allowing flexibility in how they implement the required functionality.
- **Shared Code Reuse**: Abstract classes can contain concrete methods and properties that all derived classes inherit, reducing code duplication.
- **Polymorphism Support**: You can use abstract class references to point to objects of any derived class, enabling polymorphic behavior.

**Example**
```csharp
// Abstract base class
public abstract class Animal
{
    // Concrete property - inherited by all derived classes
    public string Name { get; set; }
    
    // Concrete method - inherited by all derived classes
    public void Sleep()
    {
        Console.WriteLine($"{Name} is sleeping");
    }
    
    // Abstract method - must be implemented by derived classes
    public abstract void MakeSound();
    
    // Abstract method - must be implemented by derived classes
    public abstract void Move();
}

// Derived class - must implement all abstract methods
public class Dog : Animal
{
    public override void MakeSound()
    {
        Console.WriteLine($"{Name} barks: Woof!");
    }
    
    public override void Move()
    {
        Console.WriteLine($"{Name} runs on four legs");
    }
}

public class Bird : Animal
{
    public override void MakeSound()
    {
        Console.WriteLine($"{Name} chirps: Tweet!");
    }
    
    public override void Move()
    {
        Console.WriteLine($"{Name} flies through the air");
    }
}
```

**Usage Example**
```csharp
// Cannot do this - compilation error
// Animal animal = new Animal(); // Error!

// Can do this - polymorphism in action
Animal[] animals = {
    new Dog { Name = "Buddy" },
    new Bird { Name = "Tweety" }
};

foreach (Animal animal in animals)
{
    animal.Sleep();     // Calls inherited method
    animal.MakeSound(); // Calls overridden method
    animal.Move();      // Calls overridden method
}
```

**Abstract Classes vs Interfaces**  
While both establish contracts for derived types, abstract classes differ from interfaces because they can provide actual implementation code that derived classes inherit. Interfaces (prior to C# 8.0) could only define method signatures, while abstract classes can contain both abstract methods and concrete implementations.  
Abstract classes are particularly useful when you have a group of related classes that share common functionality but need to implement certain behaviors differently.

---

#### Q. What is the difference between sealed methods and sealed classes?  
**Sealed methods** and **Sealed classes** are both mechanisms used to control inheritance, but they apply to different aspects of class design (scope) and have distinct purposes.  
**Sealed Classes**  
- A **sealed class** is a class that cannot be inherited by any other class.
- This restriction ensures that no one can derive new classes from a sealed class; attempting to do so results in a compile-time error.
- Sealed classes are useful for preventing further inheritance, securing class hierarchies, and sometimes for enabling certain optimizations by the compiler or runtime.
```csharp
// Sealed class example
public sealed class Singleton
{
    private static readonly Singleton instance = new Singleton();

    // Private constructor prevents instantiation from outside
    private Singleton() { }

    public static Singleton Instance => instance;
}
```

**Sealed Methods**
- A **sealed method** is a method in a derived class that overrides a virtual method from a base class and then prevents further overriding by any additional derived classes.
- Only an overridden method can be marked as sealed, and it must combine the `sealed` and `override` keywords.
- This prevents further subclasses from changing (overriding) the method’s behavior, while still allowing the inheriting class to provide its own final implementation.
```csharp
public class BaseClass
{
    public virtual void Display()
    {
        Console.WriteLine("BaseClass Display");
    }
}

public class DerivedClass : BaseClass
{
    public sealed override void Display()
    {
        Console.WriteLine("DerivedClass Display");
    }
}

public class FurtherDerivedClass : DerivedClass
{
    // This would cause a compile-time error
    // public override void Display()
    // {
    //     Console.WriteLine("FurtherDerivedClass Display");
    // }
}
```
---

#### Q. What is the diamond problem in inheritance, and why doesn’t C# have it with classes?
The diamond problem is a classic inheritance ambiguity that occurs in object-oriented programming when a class inherits from two classes that both inherit from the same base class, creating a diamond-shaped inheritance hierarchy.  
Consider this scenario:  
```
    A
   / \
  B   C
   \ /
    D
```
If class D inherits from both B and C, and both B and C inherit from A, then D has two paths to reach A's members.  
This creates ambiguity: if A has a method `foo()` that both B and C override differently, which version should D inherit?  
Languages like C++ allow multiple inheritance and thus face this problem. When D tries to access a method from A, the compiler doesn't know whether to use the version that came through B or through C.  

**Why C# Doesn't Have This Problem**
C# does not support multiple inheritance for classes, which eliminates the diamond problem. In C#, a classes only support single inheritance. This means that there is a single path to the base class's members, avoiding the ambiguity present in multiple inheritance scenarios.  

**C# and Interfaces**
While C# classes don't support multiple inheritance, they do support implementing multiple interfaces. However, this doesn't create the diamond problem because:  
- **Interfaces don't contain implementation** (traditionally - though C# 8.0+ allows default interface methods)
- **No state/fields** - interfaces only define contracts
- **Explicit interface implementation** - allowing a class to define how it fulfills the contract of an interface without causing ambiguity with other interfaces or base classes

```csharp
interface IFlyable { void Fly(); }
interface ISwimmable { void Fly(); } // Same method name

class Duck : IFlyable, ISwimmable{
    public void Fly() => Console.WriteLine("Flying in air");
    
    // Explicit implementation for disambiguation
    void ISwimmable.Fly() => Console.WriteLine("Flying underwater");
}
```
Even with C# 8.0's default interface methods, the language provides mechanisms to resolve ambiguities explicitly, preventing the diamond problem from occurring.

---

#### Q. How is diamond problem resolved when interfaces are inherited from a common interface?  
When multiple interfaces are inherited from a common interface—forming a diamond-shaped hierarchy in C#—**the diamond problem is avoided because interfaces do not provide implementation or state**; they only define method signatures.

**Diamond Inheritance with Interfaces**
```csharp
interface IShape { void Draw(); }

interface IColorable : IShape { void SetColor(string color); }

interface IResizable : IShape { void Resize(double factor); }

// Diamond structure - inherits from both IColorable and IResizable
interface IAdvancedShape : IColorable, IResizable { void Animate(); }
```

**Why This Doesn't Cause Problems**  
1. **Interface Flattening**  
   C# flattens the interface hierarchy. When a class implements `IAdvancedShape`, it must implement ALL methods from the entire hierarchy:
   ```csharp
   class Rectangle : IAdvancedShape
    {
        public void Draw() => Console.WriteLine("Drawing rectangle");
        public void SetColor(string color) => Console.WriteLine($"Setting color to {color}");
        public void Resize(double factor) => Console.WriteLine($"Resizing by {factor}");
        public void Animate() => Console.WriteLine("Animating rectangle");
    }
    ```
    There's no ambiguity because there's only **one implementation of `Draw()`** in the class, even though it satisfies the contract for all interfaces that require it. Even though `Draw()` appears multiple times in the inheritance chain, the implementing class provides exactly one implementation that satisfies all the interfaces:
    ```csharp
    Rectangle rect = new Rectangle();
    IShape shape = rect;
    IColorable colorable = rect;
    IResizable resizable = rect;

    // All of these call the same Draw() method
    shape.Draw();
    colorable.Draw();  
    resizable.Draw();
    ```

2. **No State Duplication**  
    Traditional interfaces don't have fields or state, so there's no question of which "copy" of inherited state to use.

3. **Single Method Implementation**  
    Even though `Draw()` appears multiple times in the inheritance chain, the implementing class provides exactly one implementation that satisfies all the interfaces:
    ```csharp
    Rectangle rect = new Rectangle();
    IShape shape = rect;
    IColorable colorable = rect;
    IResizable resizable = rect;

    // All of these call the same Draw() method
    shape.Draw();
    colorable.Draw();  
    resizable.Draw();
    ```

**Default Interface Methods (C# 8.0+)**  
With default interface methods, you can have implementations in interfaces, which could theoretically create diamond problems:
```csharp
interface IShape { 
    void Draw() => Console.WriteLine("Default shape drawing"); 
}

interface IColorable : IShape {
    void IShape.Draw() => Console.WriteLine("Colorable shape drawing");
}

interface IResizable : IShape {
    void IShape.Draw() => Console.WriteLine("Resizable shape drawing");  
}

interface IAdvancedShape : IColorable, IResizable { }

class Shape : IAdvancedShape {
    /*
    Compiler error: Interface member 'IShape.Draw()' does not have a most specific implementation. 
    Neither 'IColorable.IShape.Draw()', nor 'IResizable.IShape.Draw()' are most specific. 
    */
}
```

**Resolution Strategies**  
C# provides several ways to resolve ambiguities:

1. **Explicit Resolution in the Interface**
    ```csharp
    interface IAdvancedShape : IColorable, IResizable {
        // Explicitly choose which implementation to use
        void IShape.Draw() => Console.WriteLine("Advanced shape drawing");
    }
    ```

2. **Class-Level Resolution**
    ```csharp
    class Rectangle : IAdvancedShape {
        // Class implementation takes precedence over interface defaults
        public void Draw() => Console.WriteLine("Rectangle drawing");
    }
    ```

3. **Most Specific Interface Wins**  
    If there's a clear "most derived" path, C# will choose that implementation automatically.


**Key Differences from Class Diamond Problem**  
- **Single Implementation**: Classes provide one implementation that satisfies multiple interface contracts
- **No State Inheritance**: No duplicate fields or properties to worry about
- **Explicit Resolution**: Language provides clear mechanisms to resolve any ambiguities
- **Compile-Time Checking**: Ambiguities are caught at compile time, not runtime  

The diamond problem with interfaces is fundamentally different because interfaces define contracts, not implementations, and C# ensures there's always a clear, unambiguous way to fulfill those contracts.

---

#### Q. How does C# resolve method calls when multiple interfaces have the same method signature?  
In C#, when a class implements multiple interfaces that have methods with the same signature, the resolution depends on how the methods are implemented and how they're called.  

**Implicit Interface Implementation**  
When you implement interfaces implicitly, all interfaces with the same method signature share a single implementation:
```csharp
interface IDrawable { void Draw(); }

interface IPrintable { void Draw(); }

class Document : IDrawable, IPrintable {
    public void Draw() {
        Console.WriteLine("Drawing document");
    }
}

// Usage - same method called regardless of interface reference
Document doc = new Document();
IDrawable drawable = doc;
IPrintable printable = doc;

doc.Draw();        // "Drawing document"
drawable.Draw();   // "Drawing document"  
printable.Draw();  // "Drawing document"
```

**Explicit Interface Implementation**  
To provide different behavior for each interface, you use explicit interface implementation:  
```csharp
class Document : IDrawable, IPrintable {
    void IDrawable.Draw() {
        Console.WriteLine("Drawing on screen");
    }
    
    void IPrintable.Draw() {
        Console.WriteLine("Drawing on paper");
    }
}

// Usage - method called depends on interface reference
Document doc = new Document();
IDrawable drawable = doc;
IPrintable printable = doc;

// doc.Draw();        // Compiler error - no public Draw method
drawable.Draw();      // "Drawing on screen"
printable.Draw();     // "Drawing on paper"
```

**Mixed Approach**  
You can combine both approaches:
```csharp
class Document : IDrawable, IPrintable {
    public void Draw() {
        Console.WriteLine("Default drawing");
    }
    
    void IPrintable.Draw() {
        Console.WriteLine("Drawing on paper");
    }
}

// IDrawable uses the public method, IPrintable uses explicit implementation
Document doc = new Document();
IDrawable drawable = doc;
IPrintable printable = doc;

doc.Draw();        // "Default drawing"
drawable.Draw();   // "Default drawing"
printable.Draw();  // "Drawing on paper"
```

**Resolution Rules**  

- **Explicit implementations take precedence** when called through their specific interface reference
- **Public implementations** are used when called directly on the object or through interfaces that don't have explicit implementations
- **Compile-time resolution** - the compiler determines which method to call based on the reference type, not the runtime type
- **No ambiguity errors** - unlike some languages, C# handles this gracefully through its interface implementation system  

This design allows you to implement interfaces with conflicting method signatures while maintaining type safety and clear semantics about which method gets called in each context.

---

#### Q. How does C# support polymorphism through inheritance?  
Inheritance-based polymorphism allows you to write flexible, extensible code where the same interface can work with objects of different types, with the correct behavior determined at runtime based on the actual object type.RetryClaude does not have the ability to run the code it generates yet.  
C# supports polymorphism through inheritance in several key ways:  

- **Virtual and Override Keywords**  
    The foundation of polymorphism in C# is the `virtual` and `override` keyword pair. A base class method marked as `virtual` can be overridden in derived classes using the `override` keyword:
    ```csharp
    public class Animal {
        public virtual void MakeSound() {
            Console.WriteLine("Some generic animal sound");
        }
    }

    public class Dog : Animal{
        public override void MakeSound() {
            Console.WriteLine("Woof!");
        }
    }

    public class Cat : Animal {
        public override void MakeSound() {
            Console.WriteLine("Meow!");
        }
    }
    ```

- **Runtime Method Resolution**  
    When you call a method on a base class reference that points to a derived class object, C# uses the actual object's type to determine which method to call:  
    ```csharp
    Animal[] animals = { new Dog(), new Cat(), new Animal() };

    foreach (Animal animal in animals) {
        animal.MakeSound(); // Calls the appropriate override based on actual type
    }
    // Output: "Woof!", "Meow!", "Some generic animal sound"
    ```

- **Abstract Classes and Methods**  
    Abstract classes provide a stronger form of polymorphism by forcing derived classes to implement certain methods:  
    ```csharp
    public abstract class Shape {
        public abstract double CalculateArea();
        
        public virtual void Display() {
            Console.WriteLine($"Area: {CalculateArea()}");
        }
    }

    public class Circle : Shape {
        private double radius;
        
        public Circle(double radius) => this.radius = radius;
        
        public override double CalculateArea() {
            return Math.PI * radius * radius;
        }
    }
    ```

- **Interface Implementation**  
    Interfaces define contracts that implementing classes must fulfill, enabling polymorphism across unrelated class hierarchies:  
    ```csharp
    public interface IDrawable {
        void Draw();
    }

    public class Rectangle : Shape, IDrawable {
        public override double CalculateArea() { /* implementation */ }
        
        public void Draw() {
            Console.WriteLine("Drawing rectangle");
        }
    }
    ```

- **Method Hiding vs. Overriding**  
    C# distinguishes between method overriding (using `override`) and method hiding (using `new`). Method hiding breaks polymorphic behavior:  
    ```csharp
    public class Base {
        public virtual void Method() => Console.WriteLine("Base");
    }

    public class Derived : Base {
        public new void Method() => Console.WriteLine("Derived");
    }

    Base obj = new Derived();
    obj.Method(); // Prints "Base" - polymorphism broken with 'new'
    ```

- **Sealed Methods and Classes**  
    The `sealed` keyword prevents further overriding of methods or inheritance of classes:  
    ```csharp
    public class BaseClass {
        public virtual void Method() { }
    }

    public class MiddleClass : BaseClass {
        public sealed override void Method() { } // Cannot be overridden further
    }
    ```
---

#### Q. What is the impact of inheritance on memory allocation in C#?  
Inheritance primarily affects memory allocation for class-based objects (reference types) on the managed heap, where the garbage collector handles lifetime and reclamation. Here are the key impacts of inheritance on memory allocation:

**Object Layout and Memory Structure**  
When you create an instance of a derived class, memory is allocated for the entire object hierarchy. The object contains fields from the base class first, followed by fields from derived classes in order of inheritance. This creates a single, contiguous memory block that includes all inherited members.
```csharp
class Animal { int age; }
class Dog : Animal { string breed; }
// A Dog instance allocates memory for both 'age' and 'breed'
```

**Increased Memory Footprint**  
Derived classes typically require more memory than their base classes because they inherit all base class fields plus their own. This can lead to larger object sizes, especially in deep inheritance hierarchies. Each level of inheritance potentially adds more fields and thus more memory overhead.  

**Virtual Method Table (vtable) Overhead**  
Objects from classes with virtual methods include a pointer to a virtual method table. This adds a small but consistent memory overhead (typically 8 bytes on 64-bit systems) to each instance. The vtable itself is shared among all instances of the same type, but each object needs the pointer.  

**Boxing and Reference Types**  
Inheritance affects how value types and reference types are handled. When you cast a derived class to a base class reference, no additional memory allocation occurs for reference types - you're just changing how you view the same object. However, boxing value types that implement interfaces does create new heap allocations.
```csharp
struct MyStruct : IComparable {
    public int Value;
    
    public int CompareTo(object obj) {
        // implementation
    }
}

MyStruct myValue = new MyStruct { Value = 42 };

// This causes BOXING - new heap allocation!
IComparable comparable = myValue;  // myValue gets boxed into an object

// This also causes boxing
object obj = myValue;  // Boxing again
```
i.e. When you have polymorphic collections or use interfaces, boxing can happen without you realizing:
```csharp
// This creates boxing for each struct!
IComparable[] items = { myStruct1, myStruct2, myStruct3 };

// Each struct gets boxed into a separate heap object
// Memory allocation happens for each one
```

**Garbage Collection Implications**  
Inheritance can impact garbage collection in several ways:  
- Objects with finalizers (destructors) require additional GC cycles
- Deep inheritance hierarchies might create more complex object graphs
- Polymorphic collections can hold references to objects of varying sizes, potentially affecting heap fragmentation  

**Memory Efficiency Considerations**  
While inheritance provides code reuse and polymorphism benefits, it can sometimes lead to memory inefficiency if base classes contain fields that aren't needed by all derived classes. In such cases, composition might be more memory-efficient than inheritance.  
The key is understanding that inheritance creates "is-a" relationships that are reflected in memory layout, where derived objects carry the full weight of their inheritance hierarchy in terms of both functionality and memory footprint.  

---

#### Q. What are potential drawbacks of deep inheritance hierarchies?  

**Complexity and Maintainability**  
As hierarchies grow deeper, understanding the complete behavior of a class requires tracing through multiple ancestor classes. This makes the codebase harder to comprehend, debug, and modify. Changes to parent classes can have unexpected ripple effects throughout the hierarchy.  

**Tight Coupling**  
Deep inheritance creates strong dependencies between classes across multiple levels. Child classes become tightly coupled not just to their immediate parent, but to the entire chain of ancestors. This makes the system fragile and resistant to change.

**Fragile Base Class Problem**  
Modifications to base classes can break derived classes in subtle ways. When inheritance chains are deep, these breaking changes can propagate through many levels, affecting classes that seem unrelated to the original change.  

**Inflexibility**  
Deep hierarchies lock you into rigid structures that are difficult to refactor. If you need to reorganize the hierarchy or extract common functionality differently, the deeply nested relationships make such changes extremely costly.  

**Method Resolution Complexity**  
In deep hierarchies, determining which version of a method gets called becomes increasingly complex, especially with method overriding. This can lead to confusing runtime behavior and difficult-to-trace bugs.  

**Violation of Composition Over Inheritance**  
Deep inheritance often indicates missed opportunities to use composition instead. Composition provides more flexibility, better testability, and clearer relationships between components.  

**Testing Difficulties**  
Testing classes deep in an inheritance hierarchy becomes challenging because you need to understand and potentially mock the entire chain of dependencies. Unit testing becomes more complex when classes carry heavy inheritance baggage.  

The general recommendation is to favor composition over inheritance and keep inheritance hierarchies shallow (typically no more than 3-4 levels deep) to maintain code clarity and flexibility.

---

#### Q. When would you choose inheritance over composition in a C# project?  
In a C# project, choosing between **inheritance** and **composition** depends on the specific design requirements, relationships between classes, and the principles of object-oriented programming. Here's a clear breakdown:  

**When to Choose Inheritance**  
Inheritance is the right choice when there is a clear "is-a" relationship between classes, and you want to model a strong, hierarchical relationship where a derived class is a specialized version of a base class. Use inheritance when: 

1. **Strong "Is-A" Relationship**:   
    - The derived class is a specific type of the base class, and this relationship is natural and unlikely to change.
    - Example: A `Dog` class inheriting from an `Animal` class because a dog *is an* animal.

2. **Shared Behavior and State**:  
    - The base class provides common behavior or state that all derived classes naturally share, and you want to avoid duplicating code.
      - Example: A `Vehicle` base class with properties like `Speed` and methods like `Move()` that apply to `Car`, `Truck`, and `Bicycle`.

3. **Polymorphism is Needed**:
    - You need to leverage polymorphism, where derived classes can override base class methods to provide specific implementations, and you want to treat all derived classes as instances of the base class.
    - Example: A `Shape` base class with a virtual `Draw()` method overridden by `Circle` and `Rectangle`.
    ```csharp
    public abstract class Shape {
        public virtual void Draw() { Console.WriteLine("Drawing a shape"); }
    }

    public class Circle : Shape {
        public override void Draw() { Console.WriteLine("Drawing a circle"); }
    }
    ```

4. **Framework or Library Requirements**:
    - Some frameworks (e.g., ASP.NET, WPF) require inheritance to extend base classes like `Controller` or `Window` to hook into their lifecycle or functionality.
    - Example: In ASP.NET, a custom controller must inherit from `ControllerBase` to integrate with the framework.

**When to Avoid Inheritance**  
- The relationship is more of a "has-a" or "uses-a" instead of "is-a" (e.g., a `Car` has an `Engine`, not is an `Engine`).
- The base class is likely to change frequently, as this can break derived classes (violating the Liskov Substitution Principle).
- You need flexibility to swap or modify behavior at runtime, which composition handles better.
- The hierarchy becomes overly complex or deep, leading to maintenance issues.

**Why Composition is Often Preferred**  
- Promotes loose coupling by allowing components to be swapped or modified without affecting the containing class.
- Supports runtime behavior changes (e.g., using dependency injection).
- Avoids the fragility of deep inheritance hierarchies.
- Aligns better with "has-a" relationships.

Example of composition:
```csharp
public class Engine {
    public void Start() { Console.WriteLine("Engine started"); }
}

public class Car {
    private readonly Engine _engine;
    public Car(Engine engine) => _engine = engine;
    public void Drive() => _engine.Start();
}
```
---

## Polymorphism
Polymorphism is a core concept in object-oriented programming that allows objects of different types to be treated as objects of a common super type, enabling the same method or operation to behave differently based on the object calling it. Polymorphism in C# is primarily achieved through **method overriding** (runtime polymorphism) and **method overloading** (compile-time polymorphism).

### 🔑 Types of Polymorphism in C#

1. **Compile-time Polymorphism (Static Binding / Early Binding)**
   - Achieved using **method overloading** and **operator overloading**.
   - Which method to call is decided at **compile time**.
    ```csharp
    class Calculator {
        public int Add(int a, int b) => a + b;
        public double Add(double a, double b) => a + b;
        public int Add(int a, int b, int c) => a + b + c;
    }

    class Program {
        static void Main() {
            Calculator calc = new Calculator();
            Console.WriteLine(calc.Add(2, 3));         // Calls int version
            Console.WriteLine(calc.Add(2.5, 3.5));     // Calls double version
            Console.WriteLine(calc.Add(1, 2, 3));      // Calls 3-parameter version
        }
    }
    ```
2. **Runtime Polymorphism (Dynamic Binding / Late Binding)**
    - Achieved using **method overriding** (with inheritance and `virtual`/`override` keywords).
    - Which method to call is decided at **runtime**, depending on the object type.
    ```csharp
    class Animal {
        public virtual void Speak() {
            Console.WriteLine("The animal makes a sound.");
        }
    }

    class Dog : Animal {
        public override void Speak() {
            Console.WriteLine("The dog barks.");
        }
    }

    class Cat : Animal {
        public override void Speak() {
            Console.WriteLine("The cat meows.");
        }
    }

    class Program {
        static void Main() {
            Animal a1 = new Dog();
            Animal a2 = new Cat();

            a1.Speak(); // Output: The dog barks.
            a2.Speak(); // Output: The cat meows.
        }
    }
    ```

### 🎯 Goals of Polymorphism
- **Code Reusability**: 
    - Write general code once, and let derived classes provide their specific behavior.
    - Example: A `List<T>` works with `int`, `string`, `Car`, or any object type, because of polymorphism.

- **Extensibility / Flexibility**:
    - New classes can be added without changing existing code, as long as they implement the same interface or override the base methods.
    - Example: Adding a new `Bird` class with `Speak()` doesn’t require changing the existing `Animal` code.

- **Loose Coupling**:
    - Code depends on **abstractions (interfaces or base classes)** instead of concrete implementations.
    - Makes systems less fragile and easier to modify.

- **Improved Readability**:
    - You can call the same method on different objects, and the behavior is appropriate without extra conditionals (`if` / `switch`).
    - Example: Instead of checking `if (animal is Dog)` everywhere, just call `animal.Speak()` and let polymorphism handle it.

- **Supports "Program to an Interface" Principle**:
    - Allows you to use dependency injection and design patterns effectively (like Strategy, Factory, Adapter).

In short, the goal of polymorphism is to **treat different objects uniformly while letting each object define its own specific behavior**.

