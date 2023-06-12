package edu.ucc.arqSoft.service.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.ResponseStatus;

import edu.ucc.arqSoft.service.dto.RegisterRequestDto;
import edu.ucc.arqSoft.service.dto.RegisterResponseDto;
import edu.ucc.arqSoft.service.service.RegisterService;

@Controller
@RequestMapping("/register")
public class RegisterController {

    @Autowired
    	private RegisterService registerService;

    @RequestMapping(value = "/{ID}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
		public @ResponseBody ResponseEntity<Object> lookupRegisterById(@PathVariable("ID") Long id) {

			RegisterResponseDto dto = registerService.getRegisterById(id);

			return new ResponseEntity<Object>(dto, HttpStatus.OK);
	}

    @RequestMapping(value = "/", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
		public @ResponseBody ResponseEntity<Object> getRegisters() {
		
			List<RegisterResponseDto> dtos = registerService.getRegisters();

			return new ResponseEntity<Object>(dtos, HttpStatus.OK);	
	}

	@RequestMapping(value = "/meditions/{ID}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
		public @ResponseBody ResponseEntity<Object> getLastDayMeditionsBySensorId(@PathVariable("ID") Long id) {
			List<RegisterResponseDto> dtos = registerService.getLastDayMeditions(id);

			return new ResponseEntity<Object>(dtos, HttpStatus.OK);	
	}

    @RequestMapping(method = RequestMethod.POST, consumes = MediaType.APPLICATION_JSON_VALUE, produces = MediaType.APPLICATION_JSON_VALUE)
		@ResponseStatus(code = HttpStatus.CREATED)
	    public @ResponseBody RegisterResponseDto newRegister(@RequestBody RegisterRequestDto request) {
		return registerService.newRegister(request);
		
	}

}
