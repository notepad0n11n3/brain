## modulos necesarios para el scrapping
#     gem install nokogiri
#     gem install httparty

require 'nokogiri'
require 'httparty'

#   https://tienda.travesiadigital.com/collections/libros-0xword

def scrapper
=begin
  url = "https://tienda.travesiadigital.com/collections/libros-0xword"
  unparsed_page = HTTParty.get(url)
  parsed_page = Nokogiri::HTML(unparsed_page.body)
  
  job_listings = parsed_page.css('.product-card__info')

  product_name = job_listings.css('.product-card__name')
  #product_price = job_listings.css('.product-card__price')
  #product_stock = job_listings.css('.product-car__availability')

  job_listings.css('.product-card__name').each do |x89p|
    nuevo = x89p.content
    nuevo = nuevo.strip
    puts nuevo
  end
=end
  owo=1
  while owo < 3
    pagina = "https://tienda.travesiadigital.com/collections/libros-0xword?page=#{owo}"
    unparsed_page = HTTParty.get(pagina)
    parsed_page = Nokogiri::HTML(unparsed_page.body)
    job_listings = parsed_page.css('.product-card__info')

    job_listings.css('.product-card__name').each do |x89p|
      nuevo = x89p.content
      nuevo = nuevo.strip
      puts nuevo
    end
    owo += 1 
  end
end

scrapper
