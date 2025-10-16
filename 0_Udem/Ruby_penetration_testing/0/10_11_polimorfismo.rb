=begin
class Persona
  def initialize(first, last, age)
    @first_name = first
    @last_name = last
    @age = age
  end

  def cumpleanos
    puts @age +=1
  end

  def presentacion(type)
    if type == "Estudiante"
      puts "Hello teacher, my name is #{@first_name} #{@last_name}"
    elsif type == "Profesor"
      puts "Hello students, I'm the teacher #{@first_name} #{@last_name}"
    elsif type == "Padres"
      puts "We're parents"
    else
      puts "Hello everyone, i'm #{@first_name} #{@last_name}"
    end
  end
end

manolo = Persona.new('Manolo', 'wowo', 88)
manolo.cumpleanos
manolo.presentacion("mango")

=end

class Persona
  def initialize(first, last, age)
    @first_name = first
    @last_name = last
    @age = age
  end

  def cumpleanos
    @age += 1
  end

  def presentacion
    puts "Hello everyone, I'm #{@first_name} #{@last_name}"
  end
end

class Estudiante < Persona
  def presentacion
    puts "Helo, I'm a student, my name is #{@first_name} #{@last_name}"
  end
end

class Profesor < Persona
  def presentacion
    puts "Hello everyone, I'm your teacher #{@first_name} #{@last_name}"
  end
end

manolo = Persona.new('Manolo', 'oe', 88)
manolo.presentacion
marco = Profesor.new('Marco', 'wowo', 88)
marco.presentacion
